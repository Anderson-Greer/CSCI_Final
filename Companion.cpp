#include "Companion.h"
#include <string>
using namespace std;

Companion::Companion()
{
    name_ = "";
    fullness_ = 50;
    armor_ = false;
}

Companion::Companion(string name)
{
    name_ = name;
    fullness_ = 50;
    armor_ = false;
}

string Companion::getName()
{
    return name_;
}

int Companion::getFullness()
{
    return fullness_;
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

int Companion::setFullness(int lost_fullness)
{
    fullness_ -= lost_fullness;
    return fullness_;
}

bool Companion::setArmor(bool armor)
{
    armor_ = armor;
    return armor_;
}