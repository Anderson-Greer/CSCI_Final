#include <string>
#include <vector>
#include <cassert>
#include "Item.cpp"
#include "Weapon.cpp"
#include "Game.cpp"
#include "User.cpp"
#include "Companion.cpp"
#include "Monster.cpp"

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
    assert(amigo1.getArmor() == false);

    Companion amigo2("Lord Farquaad", 123);
    assert(amigo2.getName() == "Lord Farquaad");
    assert(amigo2.getHealth() == 123);
    
    assert(amigo2.setArmor(true) == true);
    
    amigo2.setHealth(42);
    assert(amigo2.getHealth() == 42);

    // testing User class
    User user1;
    assert(user1.getName() == "");
    assert(user1.getIngredients().size() == 0);
    assert(user1.getWeapons().size() == 0);
    assert(user1.getArmor() == false);
    assert(user1.getCookware().size() == 0);
    assert(user1.getSellingTreasures().size() == 0);
    assert(user1.getRoomsCleared() == 0);
    assert(user1.getNumKeys() == 0);

    Item test_item1;
    Item test_item2(0.02, 20, 5, "Pan");
    Weapon test_weapon(20, 1, "Rapier");
    
    assert(user1.addIngredient(test_item1).size() == 1);
    assert(user1.addWeapon(test_weapon).size() == 1);
    assert(user1.setArmor(true) == true);
    assert(user1.addCookware(test_item2).size() == 1);
    assert(user1.addKey() == 1);
    

    // testing Monster class
    Monster monster1;
    assert(monster1.getThreat() == 0);
    assert(monster1.getHealth() == 0);
    assert(monster1.getAttack() == 0);
    assert(monster1.getName() == "");

    Monster monster2(6, 200, 30, "The Sorcerer");
    assert(monster2.getThreat() == 6);
    assert(monster2.getHealth() == 200);
    assert(monster2.getAttack() == 30);
    assert(monster2.getName() == "The Sorcerer");

    monster2.setHealth(199);
    assert(monster2.getHealth() == 199);

    return 0;
}