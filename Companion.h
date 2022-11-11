#ifndef COMPANION_H
#define COMPANION_H

#include <string>
#include <vector>

using namespace std;

class Companion {
    private:
        string name_;
        int health_;
        vector<Weapon> weapons_;
        bool armor_;
        
    public:
        // constructors
        Companion();
        Companion(string, int);

        // getter functions
        string getName();
        int getAttack();
        int getHealth();
        vector<Weapon> getWeapons();
        bool getArmor();
        // setter functions
        bool setArmor(bool);
        void setHealth(int);
        vector<Weapon> addWeapon(Weapon);
};

#endif