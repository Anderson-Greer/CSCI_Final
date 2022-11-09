#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "Weapon.cpp"

using namespace std;

class User {
    private:
        string name_;
        // vector<item> ingredients_;
        vector<Weapon> weapons_;
        // vector<item> armor_;
        // vector<item> cookware_;
        // vector<item> selling_treasures_;

        int rooms_cleared_;

    public:
        // constructors
        User();
        User(string);

        // getter functions
        string getName();
        // vector<item> getIngredients();
        vector<Weapon> getWeapons();
        // vector<item> getArmor();
        // vector<item> getCookware();
        // vector<item> getSellingTreasures();
        int getRoomsCleared();
};

#endif