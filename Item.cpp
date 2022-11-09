#include <string>
#include "Item.h"

using namespace std;

Item::Item() {
    chance_ = 0;
    cost_ = 0;
    amount_ = 0;
    name_ = "";
}

Item::Item(double chance, int cost, int amount, string name) {
    chance_ = chance;
    cost_ = cost;
    amount_ = amount;
    name_ = name;
}

double Item::getChance() {
    return chance_;
}

int Item::getCost() {
    return cost_;
}

int Item::getAmount() {
    return amount_;
}

string Item::getName() {
    return name_;
}