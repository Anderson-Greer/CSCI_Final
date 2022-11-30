#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "Game.h"

using namespace std;

bool Game::getGameOver() {
    return game_over_;
}

bool Game::setGameOver(bool status) {
    game_over_ = status;
    return game_over_;
}

void Game::printDashedLine() { // prints dashed line: +-------------+
    cout << "+-------------+" << endl;
}

void Game::printCookware(User user) { // prints the number of each type of cookware i.e.: P: 1 | F: 0 | C: 2
    int ceramic_pots = 0;
    int pans = 0;
    int cauldrons = 0;

    vector<Item> cookware = user.getCookware(); 

    for(int i = 0; i < cookware.size(); i++) {
        if(cookware.at(i).getName() == "P")
            ceramic_pots++;
        else if(cookware.at(i).getName() == "F")
            pans++;
        else if(cookware.at(i).getName() == "C")
            cauldrons++;
    }

    cout << "P: " << ceramic_pots << " | F: " << pans << " | C: " << cauldrons << endl; 
}

void Game::printWeapons(User user) { // prints the number of each type of weapon i.e.: C: 1 | S: 2 | R: 1 | B: 0 | L: 1
    int clubs = 0;
    int spears = 0;
    int rapiers = 0;
    int battle_axe = 0;
    int longsword = 0;

    vector<Weapon> weapons = user.getWeapons(); 

    for(int i = 0; i < weapons.size(); i++) {
        if(weapons.at(i).getName() == "C")
            clubs++;
        else if(weapons.at(i).getName() == "S")
            spears++;
        else if(weapons.at(i).getName() == "R")
            rapiers++;
        else if(weapons.at(i).getName() == "B")
            battle_axe++;
        else if(weapons.at(i).getName() == "L")
            longsword++;
    }

    cout << "C: " << clubs << " | S: " << spears << " | R: " << rapiers << " | B: " << battle_axe << " | L: " << longsword << endl; 
}

void Game::printTreasures(User user) { // prints the number of each type of treasure i.e.: R: 1 | N: 0 | B: 0 | C: 0 | G: 0
    int ring = 0;
    int necklace = 0;
    int bracelet = 0;
    int circlet = 0;
    int goblet = 0;

    vector<Item> treasures = user.getSellingTreasures(); 

    for(int i = 0; i < treasures.size(); i++) {
        if(treasures.at(i).getName() == "R")
            ring++;
        else if(treasures.at(i).getName() == "N")
            necklace++;
        else if(treasures.at(i).getName() == "B")
            bracelet++;
        else if(treasures.at(i).getName() == "C")
            circlet++;
        else if(treasures.at(i).getName() == "G")
            goblet++;
    }

    cout << "R: " << ring << " | N: " << necklace << " | B: " << bracelet << " | C: " << circlet << " | G: " << goblet << endl; 
}

void Game::printStatus(User user) { // prints status update
    printDashedLine();
    cout << "| STATUS      |" << endl;
    printDashedLine();
    cout << "| Rooms Cleared: " << user.getRoomsCleared() << " | Keys: " << user.getNumKeys() << " | Anger Level: " << user.getAngerLevel() << endl;
    printDashedLine();
    cout << "| INVENTORY   |" << endl;
    printDashedLine();
    cout << "| Gold        | " << user.getGold() << endl;
    cout << "| Ingredients | " << user.getIngredients() << endl;
    cout << "| Cookware    | ";
    printCookware(user);
    cout << "| Weapons     | ";
    printWeapons(user);
    cout << "| Armor       | " << user.getArmor() << endl;
    cout << "| Treasures   | ";
    printTreasures(user);
    printDashedLine();
    cout << "| PARTY       |" << endl;
    printDashedLine();
    cout << "| " << user.getName() << " | Fullness: " << user.getFullness() << endl;
    
    cout << "| " << user.getName() << " | Fullness: " << user.getFullness() << endl;
    for(int i = 0; i < user.getCompanions().size(); i++) {
        Companion compy = user.getCompanions().at(i);
        cout << "| " << compy.getName() << " | Fullness: " << compy.getFullness() << endl;
    }

    printDashedLine();
}

void Game::printInventory(User user) { // prints status update
    printDashedLine();
    cout << "| INVENTORY   |" << endl;
    printDashedLine();
    cout << "| Gold        | " << user.getGold() << endl;
    cout << "| Ingredients | " << user.getIngredients() << endl;
    cout << "| Cookware    | ";
    printCookware(user);
    cout << "| Weapons     | ";
    printWeapons(user);
    cout << "| Armor       | " << user.getArmor() << endl;
    cout << "| Treasures   | ";
    printTreasures(user);
}

/*
<<<<<<< Updated upstream
=======
    1. Check to make sure movement is valid
    2. If direction is valid, move the party using the map class and it's current position
    3. North: increase row by 1, South: decrease row by 1, West: increase column by 1, East: decrease column by 1
    4. After movement, each party member has a 20% chance of losing 1 fullness point
*/
void Game::move(char direction) { // handles the movement of the party

}

// split function
int split(string input_string, char separator, string arr[], int arr_size)
{   
    int count = 0;          // declare variables used in for loop
    int place = 0;
    arr[0] = input_string;
    
    if (input_string.length() == 0)     // input validation
    {
        return 0;
    }

    for (int i = 0; i <= input_string.length(); i++)
    {
        if (input_string[i] == separator)       // checks if char == separator
        {
            arr[count] = input_string.substr(place, i - place);     // populates array with correct substring
            count++;            // increments array index
            place = i + 1;      // updates place value so next string starts at correct spot
            
            if (count >= arr_size)      // checks if array is at capacity
            {
                return -1;
            }
        }
    }
    arr[count] = input_string.substr(place, input_string.length() - place);     // populates last array spot
    
    return count + 1;
}

void Game::printNPCinteraction() // prints NPC space action menu
{
    string input;
    cout << "Your party has encountered an NPC!\n" << endl;
    cout << "Please choose one of the following: \n";
    cout << "  1. Move \n";
    cout << "  2. Speak to NPC \n";
    cout << "  3. Give up \n";

    cin >> input;

    switch (stoi(input))
    {
        /*case 1: 
        {

        }*/

        case 2: 
        {
            string line;
            vector<string> riddleVect;
            ifstream riddles("riddles.txt");

            cout << "The NPC is willing to offer you help, but you must solve this riddle first:" << endl;

            while (getline(riddles, line))
            {
                riddleVect.push_back(line);
            }

            int random = rand % riddleVect.size();
            string riddle = riddleVect[random];
            split(riddle, '~', arr, 2);

            cout << arr[0] << endl;
            cin >> input;

            if (input == arr[1])
            {
                Merchant NPC(user);
                NPC.printInteraction(game, user);
            }

            map.removeNPC(getPlayerRow(), getPlayerCol());
        }
    }


}

/*
>>>>>>> Stashed changes
    1. Check if space is already explored or not
    2. If it is, tell player to choose something else, if not, continue function
    3. Run random number, 10% chance player finds key, 20% chance player finds treasure, 20% chance player has to fight random monster
    4. 50% chance party member's fullness drops by 1 point
*/
void Game::investigate() { // handles the investigation of a space

}

/*
    1. Given monster, calculate if party defeats it or not
    2. If fight is won, party gains 10 * diff of monster gold pieces and 5 * diff of monster kg of ingredients
    3. 10% chance monster drops a key
    4. If monster is defeated, remove monster from list of possible monsters
    5. If party is defeated, they lose a quarter of gold reserves, 30kg of ingredients, and a chance that each party member dies
        (10% chance of death without armor, 5% with armor)
*/
// void Game::fight(Monster monster) { // handles picking a fight

// }

/*
    1. Check to see if cookware breaks while cooking given it's chance of breaking
    2. If it doesn't break, fullness gained = kg of ingredients / 5
*/
void Game::cookAndEat(Item, double) { // handles cooking and eating ingredients

}

/*
    1. Print message stating that the game ended
*/
void Game::giveUp() { // handles giving up

}
