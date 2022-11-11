#ifndef MONSTER_H
#define MONSTER_H

#include <string>

using namespace std;

class Monster
{
    private:
        int threat_level_;
        int health_;
        int attack_;
        string name_;
    public:
        Monster();
        Monster(int, int, int, string);
        int getThreat();
        int getHealth();
        int getAttack();
        string getName();

        int setHealth(int);
};

#endif