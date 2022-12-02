#include <string>
#include <vector>
#include <cassert>
#include <iostream>
#include "Item.cpp"
#include "Weapon.cpp"
#include "Companion.cpp"
#include "Map.cpp"
#include "Merchant.cpp"
#include "NPC.cpp"
#include "User.cpp"




using namespace std;

int main() {
    srand((unsigned) time(NULL));

    // create the user
    string player_name;
    cout << "Enter a name for your character: " << endl;
    getline(cin, player_name);
    User user(player_name);
    user.setGameOver(false);

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
    merchant.printInteraction(user); 
    user.loadMonsters(); // loads in the monsters txt file

    Map map; // create the map
    map.createMap();
    map.displayMap();

    while(!user.getGameOver()) {
        // game ends from angry sorceror, player loses
        if(user.getAngerLevel() >= 100) {
            cout << "You made the sorceror too angry. He reached an anger level of 100, and opened a portal to hell under your feet." <<
                "\nGAME OVER" << endl;
            user.setGameOver(true);
        }
        // game ends from player escaping, player wins
        else if(user.getRoomsCleared() >= 5 && map.isDungeonExit(map.getPlayerRow(), map.getPlayerCol())) {
            cout << "CONGRATULATIONS, YOU MADE IT OUT!!!!!!!" << endl;
            user.setGameOver(true);
        }
        // game continues
        else {
            user.runPlayerAction(map, user);
            
            if(!user.getGameOver()) {
                user.printStatus();
                map.displayMap();
            }
        }
    }

    return 0;
}