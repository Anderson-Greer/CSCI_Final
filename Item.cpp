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

double Item::setChance(double chance) {
    chance_ = chance;
    return chance_;
}

int Item::setCost(int cost) {
    cost_ = cost;
    return cost_;
}

int Item::setAmount(int amount) {
    amount_ = amount;
    return amount_;
}

string Item::setName(string name) {
    name_ = name;
    return name_;
}