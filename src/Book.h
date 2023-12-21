//
// Created by Aaron Alvarez on 12/21/23.
//

#ifndef MARKET_MAKER_SIMULATION_BOOK_H
#define MARKET_MAKER_SIMULATION_BOOK_H

#include "Limit.h"

class Book { // the actual binary tree
private:
    Limit *buyTree;
    Limit *sellTree;
    Limit *lowestBuy;
    Limit *highestBuy;
public:
    void addOrder(Order *order);
    void cancelOrder(int orderId);
    int getVolumeAtPrice(int price, bool buyOrSell);
    int getBestPrice(bool buyOrSell);

};


#endif //MARKET_MAKER_SIMULATION_BOOK_H
