#ifndef COMPANION_H
#define COMPANION_H

#include <string>
#include <vector>

using namespace std;

class Companion {
    private:
        string name_;
        int fullness_;
        vector<Weapon> weapons_;
        bool armor_;
        
    public:
        // constructors
        Companion();
        Companion(string);

        // getter functions
        string getName();
        int getAttack();
        int getFullness();
        vector<Weapon> getWeapons();
        bool getArmor();
        // setter functions
        bool setArmor(bool);
        int setFullness(int);
        vector<Weapon> addWeapon(Weapon);
};

#endif