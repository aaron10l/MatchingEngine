//
// Created by Aaron Alvarez on 12/21/23.
//

#ifndef MARKET_MAKER_SIMULATION_ORDER_H
#define MARKET_MAKER_SIMULATION_ORDER_H

class Limit; // telling the compiler about Limit, aka forward declaration

class Order {
public:
    int idNumber;
    bool buyOrSell;
    int shares;
    int limit;
    int entryTime;
    int eventTime;
    Limit *parentLimit;
};


#endif //MARKET_MAKER_SIMULATION_ORDER_H
