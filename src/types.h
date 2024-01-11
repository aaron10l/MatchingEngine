#ifndef TYPES_H_
#define TYPES_H_

#include <string>
#include <limits>

/* Order Id */
using t_orderid = unsigned long;

/* Price
   0-65536 interpreted as divided by 100
   eg the range is 000.00-655.36
   eg the price 123.45 = 12345
   eg the price 23.45 = 2345
   eg the price 23.4 = 2340 */
using t_price = unsigned short;

/* Order Size */
using t_size = unsigned long;

/* Side
   Ask=1, Bid=0 */
using t_side = int;

struct t_order {
    std::string symbol;
    std::string trader;
    t_side side;
    t_price price;
    t_size size;
};

using t_execution = t_order;

#endif