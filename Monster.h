#ifndef MONSTER_H
#define MONSTER_H

#include <string>

using namespace std;

class Monster
{
    private:
        int threat_level_;
        int attack_;
        string name_;
    public:
        Monster();
        Monster(int, int, string);
        int getThreat();
        int getAttack();
        string getName();
};

#endif