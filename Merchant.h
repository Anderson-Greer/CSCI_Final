#ifndef MERCHANT_H
#define MERCHANT_H

#include <string>
#include <vector>
#include "User.h"
#include "Game.h"

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
        void printInteraction(Game, User&);
};

#endif