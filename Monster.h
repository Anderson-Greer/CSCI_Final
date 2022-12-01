#ifndef MONSTER_H
#define MONSTER_H

#include <string>
#include <vector>

using namespace std;

class Monster
{
    private:
        int threat_level_;
        int attack_;
        string name_;
        vector<string> monsters_;
        vector<string> defeated_monsters_;

    public:
        Monster();
        Monster(int, int, string);
        int getThreat();
        int getAttack();
        string getName();

        vector<string> loadMonsters(); // pulls a monster from the txt file to be used in a fight
        void fightMonster(User);
        void surrender(User&);
};

#endif