#include <string>
#include <vector>
#include <cassert>
#include "Item.cpp"
#include "Weapon.cpp"
#include "Companion.cpp"
#include "User.cpp"
#include "Monster.cpp"
#include "Game.cpp"

using namespace std;

int main() {

    Game game;
    game.setGameOver(false);

    // while(!game.getGameOver()) { // runs loop while game is not over

    // }



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
    assert(amigo1.getFullness() == 50);

    Companion amigo2("Lord Farquaad");
    assert(amigo2.getName() == "Lord Farquaad");
    assert(amigo2.getFullness() == 50);
    assert(amigo2.setFullness(42) == 8);

    // testing User class
    User user1;
    assert(user1.getName() == "");
    assert(user1.getWeapons().size() == 0);
    assert(user1.getArmor() == 0);
    assert(user1.getCookware().size() == 0);
    assert(user1.getSellingTreasures().size() == 0);
    assert(user1.getRoomsCleared() == 0);
    assert(user1.getNumKeys() == 0);
    assert(user1.getFullness() == 50);

    Item test_item1;
    Item test_item2(0.02, 20, 5, "Pan");
    Weapon test_weapon(20, 1, "Rapier");

    User user2("Andy");
    assert(user2.getName() == "Andy");
    assert(user2.setIngredients(15) == 15);
    assert(user2.addWeapon(test_weapon).size() == 1);
    assert(user2.setArmor(4) == 4);
    assert(user2.addCookware(test_item2).size() == 1);
    assert(user2.addKey() == 1);
    assert(user2.setFullness(10) == 40); // removes 10 fullness from the fullness variable
    user2.addCompanion(amigo2);
    assert(user2.getCompanions().size() == 1);

    game.printStatus(user2);
    

    // // testing Monster class
    // Monster monster1;
    // assert(monster1.getThreat() == 0);
    // assert(monster1.getAttack() == 0);
    // assert(monster1.getName() == "");

    // Monster monster2(6, 30, "The Sorcerer");
    // assert(monster2.getThreat() == 6);
    // assert(monster2.getAttack() == 30);
    // assert(monster2.getName() == "The Sorcerer");

    return 0;
}