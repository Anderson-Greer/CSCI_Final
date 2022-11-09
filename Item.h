#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std;

class Item {
    private:
        double chance_; // chance that item breaks on use(for cookware)
        int cost_; // cost of item
        int amount_; // amount of item purchased(for ingredients)
        string name_; // name of item(for cookware)
        
    public:
        // constructors
        Item();
        Item(double, int, int, string);

        // getter functions
        double getChance();
        int getCost();
        int getAmount();
        string getName();
};

#endif