#ifndef MERCHANT_H
#define MERCHANT_H

#include <string>
#include <vector>
#include "User.h"
using namespace std;

class Merchant {
    private:
        double price_multiplier_;
        
    public:
        // constructors
        Merchant(User);

        // getter functions
        

        // setter functions
        

        // other functions
        void printInteraction(User&);
};

#endif