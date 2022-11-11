#include "Companion.h"
#include <string>
using namespace std;

Companion::Companion()
{
    name_ = "";
    health_ = 0;
    armor_ = false;
}

Companion::Companion(string name, int health)
{
    name_ = name;
    health_ = health;
    armor_ = false;
}

string Companion::getName()
{
    return name_;
}

int Companion::getHealth()
{
    return health_;
}

bool Companion::getArmor()
{
    return armor_;
}

vector<Weapon> Companion::getWeapons()
{
    return weapons_;
}

vector<Weapon> Companion::addWeapon(Weapon newWeapon)
{
    weapons_.push_back(newWeapon);
    return weapons_;
}

int Companion::setHealth(int health)
{
    health_ = health;
    return health_;
}

bool Companion::setArmor(bool armor)
{
    armor_ = armor;
    return armor_;
}