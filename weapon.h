#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include <vector>

using namespace std;

class Weapon {
    private:
        int cost_;
        int damage_;
        string name_;

    public:
        // constructors
        Weapon();
        Weapon(int, int, string);

        // getter functions
        int getCost();
        int getDamage();
        string getName();
};

#endif