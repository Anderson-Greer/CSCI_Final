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
        vector<Item> armor_;
        
    public:
        // constructors
        Companion();
        Companion(string, int, int);

        // getter functions
        string getName();
        int getAttack();
        int getHealth();
        vector<Weapon> getWeapons();
        vector<Item> getArmor();

        void setHealth(int health);
};

#endif