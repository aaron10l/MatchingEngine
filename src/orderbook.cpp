//
// Created by Aaron Alvarez on 1/4/24.
//
#include "orderbook.h"
#include "engine.h"
#include "limits.h" // our own custom limits


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
        if (price >= askMin){ //
            auto ppEntry = pricePoints.begin() + askMin;
            do {
                auto bookEntry = ppEntry->begin();  // used to return iterator to first element to avoid 0 indexing
                while (bookEntry != ppEntry->end()){
                    if (bookEntry->size < order_size){
                        executeTrade(order.symbol, order.trader, bookEntry->trader, price, bookEntry->size);
                        order_size -= bookEntry->size;
                        bookEntry++;
                    } else {
                        executeTrade(order.symbol, order.trader, bookEntry->trader, price, order_size);
                        if (bookEntry->size > order_size)
                            bookEntry->size -= order_size;
                        else
                            bookEntry++;
                    }
                }

            }

        }
    }
}