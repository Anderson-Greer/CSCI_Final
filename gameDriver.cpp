#include <string>
#include <vector>
#include <cassert>
#include <iostream>
#include "Item.cpp"
#include "Weapon.cpp"
#include "Companion.cpp"
#include "Map.cpp"
#include "Merchant.cpp"
#include "Game.cpp"
#include "User.cpp"
#include "Monster.cpp"
#include "NPC.cpp"


using namespace std;

int main() {

    Game game;
    game.setGameOver(false);

    // create the user
    string player_name;
    cout << "Enter a name for your character: " << endl;
    getline(cin, player_name);
    User user(player_name);

    // create the four companions
    cout << "You will now enter the names of your four companions." << endl;
    for(int i = 0; i < 4; i++) {
        string companion_name;
        cout << "Enter the name of companion " << i + 1 << ":" << endl;
        getline(cin, companion_name);
        Companion comp(companion_name);
        user.addCompanion(comp); // add each new companion to the companion vector in the user class
    }

    cout <<  "Between the five of you, you have 100 gold pieces.\nYou will need to spend the some of your money on the following items:" <<
        "\n\n- INGREDIENTS. To make food, you have to cook raw ingredients." <<
        "\n- COOKWARE. If you want to cook, you have to have cookware first." <<
        "\n- WEAPONS. You'll want at least one weapon per party member to fend off monsters." <<
        "\n- ARMOR. Armor increases the chances of surviving a monster attack." <<
        "\n\nYou can spend all of your money here before you start your journey, or you can save some to spend on merchants along the way." <<
        "\nBut beware, some of the merchants in this dungeon are shady characters, and they won\'t always give you a fair price..." << endl;

    Merchant merchant(user); // create starting merchant
    merchant.printInteraction(game, user); 

    Map map; // create the map
    map.createMap();
    map.displayMap();
    map.addNPC(1,1);

    while(!game.getGameOver()) {
        // game ends from angry sorceror, player loses
        if(user.getAngerLevel() >= 100) {
            cout << "You made the sorceror too angry. He reached an anger level of 100, and opened a portal to hell under your feet." <<
                "\nGAME OVER" << endl;
            game.setGameOver(true);
        }
        // game ends from player escaping, player wins
        else if(user.getRoomsCleared() >= 5 && map.isDungeonExit(map.getPlayerRow(), map.getPlayerCol())) {
            cout << "CONGRATULATIONS, YOU MADE IT OUT!!!!!!!" << endl;
            game.setGameOver(true);
        }
        // game continues
        else {
            user.runPlayerAction(map, game, user);

            map.displayMap();
        }
    }

    // // testing Weapon class
    // Weapon weapon1;
    // assert(weapon1.getCost() == 0);
    // assert(weapon1.getDamage() == 0);
    // assert(weapon1.getName() == "");

    // Weapon weapon2(50, 3, "longsword");
    // assert(weapon2.getCost() == 50);
    // assert(weapon2.getDamage() == 3);
    // assert(weapon2.getName() == "longsword");

    // // testing Item class
    // Item item1;
    // assert(item1.getChance() == 0.0);
    // assert(item1.getCost() == 0);
    // assert(item1.getAmount() == 0);
    // assert(item1.getName() == "");

    // Item item2(0.02, 20, 1, "cauldron");
    // assert(item2.getChance() == 0.02);
    // assert(item2.getCost() == 20);
    // assert(item2.getAmount() == 1);
    // assert(item2.getName() == "cauldron");

    // // testing User class
    // User user1;
    // assert(user1.getName() == "");
    // assert(user1.getWeapons().size() == 0);
    // assert(user1.getArmor() == 0);
    // assert(user1.getCookware().size() == 0);
    // assert(user1.getSellingTreasures().size() == 0);
    // assert(user1.getRoomsCleared() == 0);
    // assert(user1.getNumKeys() == 0);
    // assert(user1.getFullness() == 50);

    // Item test_item1;
    // Item test_item2(0.02, 20, 5, "Pan");
    // Weapon test_weapon(20, 1, "Rapier");

    // Item treasure1(0, 10, 1, "R");
    // Item treasure2(0, 50, 1, "G");
    // user.addTreasure(treasure1);
    // user.addTreasure(treasure2);

    // user.increaseRoomsCleared();
    // user.increaseRoomsCleared();
    // user.increaseRoomsCleared();
    // user.increaseRoomsCleared();


    // game.printStatus(user);

    // Merchant merchant(user);

    // merchant.printInteraction(game, user);
    merchant.printInteraction(game, user);


    Weapon weapon3(10, 1, "C");
    Weapon weapon4(20, 2, "S");
    Weapon weapon5(30, 3, "R");
    Weapon weapon6(40, 6, "L");
    
    
    user.addWeapon(weapon5);
    user.addWeapon(weapon6);
    user.addWeapon(weapon4);
    user.addWeapon(weapon3);

    user.bubbleSortWeapons();

    for (int i = 0; i < user.getWeapons().size(); i ++)
    {
        cout << user.getWeapons().at(i).getDamage() << endl;
    }
    

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