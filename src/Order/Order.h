//
// Created by Aaron Alvarez on 12/18/23.
//

#ifndef EXCHANGESIMULATOR_ORDER_H
#define EXCHANGESIMULATOR_ORDER_H

#include <string>
#include <ctime>

class Order {
public:
    int orderId;
    time_t timestamp;
    bool buyOrSell;
    double price;
    int volume;
    std::string client;
};


#endif //EXCHANGESIMULATOR_ORDER_H
