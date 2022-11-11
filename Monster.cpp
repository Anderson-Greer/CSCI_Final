#include "Monster.h"
#include <string>

using namespace std;

Monster::Monster()
{
    threat_level_ = 0;
    health_ = 0;
    attack_ = 0;
    name_ = "";
}

Monster::Monster(int threat_level, int health, int attack, string name)
{
    threat_level_ = threat_level;
    health_ = health;
    attack_ = attack;
    name_ = name;
}

int Monster::getThreat()
{
    return threat_level_;
}

int Monster::getHealth()
{
    return health_;
}

int Monster::getAttack()
{
    return attack_;
}

string Monster::getName()
{
    return name_;
}

int Monster::setHealth(int health)
{
    health_ = health;
    return health_;
}