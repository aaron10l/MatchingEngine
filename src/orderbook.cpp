//
// Created by Aaron Alvarez on 1/4/24.
//
#include "orderbook.h"
#include "engine.h"
#include "limits.h" // custom limits


OrderBook& OrderBook::get() {
    static OrderBook ob;
    return ob;
}

void executeTrade(std::string& symbol, std::string& buyTrader, std::string& sellTrader, t_price tradePrice, t_size tradeSize){
    t_execution exec;
    if (tradeSize == 0){
        return;
    }

    exec.symbol = symbol;
    exec.price = tradePrice;
    exec.size = tradeSize;
    exec.side = 0;
    exec.trader = buyTrader;
    execution(exec);    // reporting buy side of trade

    exec.side = 1;
    exec.trader = sellTrader;
    execution(exec);    // reporting sell side trade
}

void OrderBook::initialize() {
    pricePoints.resize(MAX_PRICE);
    for (auto& each : pricePoints){
        each.clear();
    }

    arenaBookEntries.resize(MAX_TOTAL_ORDERS);
    currOrderId = 0;
    askMin = MAX_PRICE;
    bidMax = MIN_PRICE;
}

void OrderBook::shutdown() {

}

t_orderid OrderBook::limit(t_order& order){
    t_price price = order.price;
    t_size order_size = order.size;

    if (order.side == 0){   // is a buy order
        if (price >= askMin){   // the incoming order crosses the spread
            auto pricepointEntry = pricePoints.begin() + askMin;
            do {
                auto bookEntry = pricepointEntry->begin();
                while (bookEntry != pricepointEntry->end()){
                    if (bookEntry->size < order_size){
                        executeTrade(order.symbol, order.trader, bookEntry->trader, price, bookEntry->size);
                        order_size -= bookEntry->size;
                        bookEntry++;
                    } else {
                        executeTrade(order.symbol, order.trader, bookEntry->trader, price, order_size);
                        if (bookEntry->size > order_size){
                            bookEntry->size -= order_size;
                        } else {
                            bookEntry++;
                        }
                        pricepointEntry->erase(pricepointEntry->begin(), bookEntry);
                        while (pricepointEntry->begin() != bookEntry){
                            pricepointEntry->pop_front();
                        }
                        return ++currOrderId;
                    }
                }
                // there are no remaining orders at the askMin pricepoint. we will move to the next level.
                pricepointEntry->clear();
                pricepointEntry++;
                askMin++;
            } while (price >= askMin);
        }

        auto new_entry = arenaBookEntries.begin() + (++currOrderId);
        new_entry->size = order_size;
        new_entry->trader = order.trader;
        pricePoints[price].push_back(*new_entry);
        if (bidMax < price) bidMax = price;
        return currOrderId;
    } else {    // is a sell order
        if (price <= bidMax){   // the order crosses the spread
            auto pricepointEntry = pricePoints.begin() + bidMax;
            do {
                auto bookEntry = pricepointEntry->begin();
                while (bookEntry != pricepointEntry->end()){
                    if (bookEntry->size < order_size){
                        executeTrade(order.symbol, bookEntry->trader, order.trader, price, bookEntry->size);
                        order_size -= bookEntry->size;
                        bookEntry++;
                    } else {
                        executeTrade(order.symbol, bookEntry->trader, order.trader, price, order_size);
                        if (bookEntry->size > order_size){
                            bookEntry->size -= order_size;
                        } else {
                            bookEntry++;
                        }
                        while (pricepointEntry->begin() != bookEntry){
                            pricepointEntry->pop_front();
                        }
                        return ++currOrderId;
                    }
                }
                // we are out of orders at the bidMax pricepoint. move on to the next price level.
                pricepointEntry->clear();
                pricepointEntry--;
                bidMax--;
            } while (price <= bidMax);
        }

        auto new_entry = arenaBookEntries.begin() + (++currOrderId);
        new_entry->size = order_size;
        new_entry->trader = order.trader;
        pricePoints[price].push_back(*new_entry);
        if (askMin > price) askMin = price;
        return currOrderId;
    }
}

void OrderBook::cancel(t_orderid orderid) {
    // cancels by setting order volume to 0
    arenaBookEntries[orderid].size = 0;
}