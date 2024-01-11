#include <limits>
#include <cstdint>
#include "types.h"

constexpr t_price MIN_PRICE = 1;
constexpr t_price MAX_PRICE = std::numeric_limits<t_price>::max();
constexpr int MAX_TOTAL_ORDERS = 101000;
constexpr uint32_t MAX_LIVE_ORDERS = std::numeric_limits<uint32_t>::max();
