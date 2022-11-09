#include <string>
#include "Weapon.h"

using namespace std;

Weapon::Weapon() {
    cost_ = 0;
    damage_ = 0;
    name_ = "";
}

Weapon::Weapon(int cost, int damage, string name) {
    cost_ = cost;
    damage_ = damage;
    name_ = name;
}

int Weapon::getCost() {
    return cost_;
}

int Weapon::getDamage() {
    return damage_;
}

string Weapon::getName() {
    return name_;
}