#ifndef COMPANION_H
#define COMPANION_H

#include <string>
#include <vector>
#include "Weapon.cpp"

using namespace std;

class Companion {
    private:
        string name_;
        int health_;
        int attack_;
        vector<Weapon> weapons_;
        
    public:
        Companion();
        Companion(string, int, int);

        string getName();
        int getAttack();
        int getHealth();

        void setHealth(int health);
};

#endif