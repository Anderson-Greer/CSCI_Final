#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

using namespace std;

class User {
    private:
        string name_;
        vector<Item> ingredients_;
        vector<Weapon> weapons_;
        vector<Item> cookware_;
        vector<Item> selling_treasures_;
        bool armor_;
        int keys_;

        int rooms_cleared_;

    public:
        // constructors
        User();
        User(string);

        // getter functions
        string getName();
        vector<Item> getIngredients();
        vector<Weapon> getWeapons();
        bool getArmor();
        vector<Item> getCookware();
        vector<Item> getSellingTreasures();
        int getRoomsCleared();
        int getNumKeys();

        // setter functions
        vector<Item> addIngredient(Item); // add ingredient to ingredients vector
        vector<Weapon> addWeapon(Weapon); // add weapon to weapons vector
        bool setArmor(bool); // changes armor value of player (true if player has armor, false if not) and returns value set
        vector<Item> addCookware(Item); // add cookware to cookware vector
        int addKey(); // adds a key to key count and returns the new number of keys

        // other functions
        void bubbleSortWeapons(vector<Weapon>);
};

#endif