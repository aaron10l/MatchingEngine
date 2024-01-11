#ifndef ENGINE_H_
#define ENGINE_H_

#include <limits>
#include "types.h"


void init();

void destroy();

t_orderid limit(t_order order);

void cancel(t_orderid orderid);

void execution(t_execution exec);


#endif // ENGINE_H_
