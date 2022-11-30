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
        vector<Item> addTreasure(Item); // add selling treasure to treasure vector
        vector<Item> removeTreasure(int); // remove selling treasure from treasure vector
        int addKey(); // adds a key to key count and returns the new number of keys
        int increaseRoomsCleared(); // adds one to the number of rooms cleared
        int setFullness(int); // removes parameter health from health value
        int setAngerLevel(int); // sets the anger level
        int setGold(int); // sets the amount of gold
        int setIngredients(int); // set the amount of ingredients
        int setArmor(int); // stores the number of sets of armor the party holds

        // other functions
        void bubbleSortWeapons(vector<Weapon>);
};

#endif