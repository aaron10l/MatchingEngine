//
// Created by Aaron Alvarez on 1/4/24.
//

#ifndef EXCHANGESIMULATOR_ORDERBOOK_H
#define EXCHANGESIMULATOR_ORDERBOOK_H

#include "types.h"
#include <vector>
#include <boost/intrusive/slist.hpp>
#include <boost/intrusive/list.hpp>
#include <string>


class OrderBook {
public:
    static OrderBook& get();
    void initialize();
    void shutdown();
    t_orderid limit(t_order& order);
    void cancel(t_orderid orderid);

private:
    OrderBook(){}

    struct orderbookEntry : public boost::intrusive::slist_base_hook<>{
        t_size size{0};
        std::string trader;
    };

    typedef boost::intrusive::slist <orderbookEntry, boost::intrusive::cache_last<true> > pricePoint;
    std::vector<orderbookEntry> arenaBookEntries;
    std::vector<pricePoint> pricePoints;
    t_orderid currOrderId;
    t_price askMin;
    t_price bidMax;
};


#endif //EXCHANGESIMULATOR_ORDERBOOK_H
