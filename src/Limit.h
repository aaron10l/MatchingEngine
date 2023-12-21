//
// Created by Aaron Alvarez on 12/21/23.
//

#ifndef MARKET_MAKER_SIMULATION_LIMIT_H
#define MARKET_MAKER_SIMULATION_LIMIT_H

#include "Order.h"

class Limit { // acts as a "container" for the linked list of orders (is the price limit)
public:
    int limitPrice;
    int size;
    int totalVolume;
    Limit *parent;
    Limit *leftChild;
    Limit *rightChild;
    Order *headOrder;
    Order *tailOrder;
};


#endif //MARKET_MAKER_SIMULATION_LIMIT_H
