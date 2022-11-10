#include "Companion.h"
#include <string>
using namespace std;

Companion::Companion()
{
    name_ = "";
    health_ = 0;
}

Companion::Companion(string name, int health)
{
    name_ = name;
    health_ = health;
}

string Companion::getName()
{
    return name_;
}

int Companion::getHealth()
{
    return health_;
}

void Companion::setHealth(int health)
{
    health_ = health;
    return;
}