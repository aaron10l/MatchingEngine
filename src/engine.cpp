#include "engine.h"
#include "orderbook.h"


void init() { OrderBook::get().initialize(); }

void destroy() { OrderBook::get().shutdown(); }

t_orderid limit(t_order order) { return OrderBook::get().limit(order); }

void cancel(t_orderid orderid) { OrderBook::get().cancel(orderid); }
