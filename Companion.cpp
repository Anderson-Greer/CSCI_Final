#include "Companion.h"
#include <string>
using namespace std;

Companion::Companion()
{
    name_ = "";
    health_ = 0;
    attack_ = 0;
}

Companion::Companion(string name, int health, int attack)
{
    name_ = name;
    health_ = health;
    attack_ = attack;
}

string Companion::getName()
{
    return name_;
}

int Companion::getHealth()
{
    return health_;
}

int Companion::getAttack()
{
    return attack_;
}

void Companion::setHealth(int health)
{
    health_ = health;
    return;
}