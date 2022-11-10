#include <string>
#include <vector>
#include <cassert>
// #include "User.h"
#include "Item.cpp"
#include "Weapon.cpp"
#include "Companion.cpp"

using namespace std;

int main() {
    // testing Weapon class
    Weapon weapon1;
    assert(weapon1.getCost() == 0);
    assert(weapon1.getDamage() == 0);
    assert(weapon1.getName() == "");

    Weapon weapon2(50, 3, "longsword");
    assert(weapon2.getCost() == 50);
    assert(weapon2.getDamage() == 3);
    assert(weapon2.getName() == "longsword");

    // testing Item class
    Item item1;
    assert(item1.getChance() == 0.0);
    assert(item1.getCost() == 0);
    assert(item1.getAmount() == 0);
    assert(item1.getName() == "");

    Item item2(0.02, 20, 1, "cauldron");
    assert(item2.getChance() == 0.02);
    assert(item2.getCost() == 20);
    assert(item2.getAmount() == 1);
    assert(item2.getName() == "cauldron");

    // testing Companion class
    Companion amigo1;
    assert(amigo1.getName() == "");
    assert(amigo1.getHealth() == 0);
    assert(amigo1.getAttack() == 0);

    Companion amigo2("Lord Farquaad", 123, 69);
    assert(amigo2.getName() == "Lord Farquaad");
    assert(amigo2.getHealth() == 123);
    assert(amigo2.getAttack() == 69);
    
    amigo2.setHealth(42);
    assert(amigo2.getHealth() == 42);

    return 0;
}