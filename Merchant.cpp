#include "Merchant.h"
#include <string>
using namespace std;

Merchant::Merchant(User user)
{
    price_multiplier_ = 1 + (0.25 * user.getRoomsCleared());
}