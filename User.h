#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

using namespace std;

class User {
    private:
        string name_;
        vector<Weapon> weapons_; // store each piece of weapon by letter name i.e.: club is C
        vector<Item> cookware_; // store each piece of cookware by letter name i.e.: ceramic pot is P
        vector<Item> selling_treasures_; // store each piece of cookware by letter name i.e.: silver ring is R
        vector<Companion> companions_;
        int armor_;
        int keys_;
        int fullness_;
        int rooms_cleared_;
        int anger_level_;
        int gold_;
        int ingredients_;

    public:
        // constructors
        User();
        User(string);

        // getter functions
        string getName();
        vector<Weapon> getWeapons();
        vector<Item> getCookware();
        vector<Item> getSellingTreasures();
        vector<Companion> getCompanions();
        int getArmor();
        int getRoomsCleared();
        int getNumKeys();
        int getFullness();
        int getAngerLevel();
        int getGold();
        int getIngredients();

        // setter functions
        vector<Weapon> addWeapon(Weapon); // add weapon to weapons vector
        vector<Item> addCookware(Item); // add cookware to cookware vector
        vector<Companion> addCompanion(Companion); // add companion to companion vector
        vector<Item> addTreasure(); // add selling treasure to treasure vector
        vector<Item> removeTreasure(int); // remove selling treasure from treasure vector
        int addKey(); // adds a key to key count and returns the new number of keys
        int increaseRoomsCleared(); // adds one to the number of rooms cleared
        int setFullness(int); // removes parameter health from health value
        void changePartyFullness(int); // removes or adds an equal amount of fullness from each party member
        int setAngerLevel(int); // sets the anger level
        int setGold(int); // sets the amount of gold
        int setIngredients(int); // set the amount of ingredients
        int setArmor(int); // stores the number of sets of armor the party holds

        // other functions
        void printDashedLine(); // prints a dashed line to be used in printStatus
        void printCookware(); // prints the number of each type of cookware, to be used in printStatus
        void printWeapons(); // prints the number of each type of weapon, to be used in printStatus
        void printTreasures(); // prints the number of each type of treasure, to be used in printStatus
        void printStatus(); // prints the status update
        void printInventory(); // prints the current inventory of the user
        void runPlayerAction(Map&, User); // goes through a player action
        void bubbleSortWeapons(vector<Weapon>);
        void bubbleSortWeapons();
};

#endif