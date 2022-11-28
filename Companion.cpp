#include "Companion.h"
#include <string>
using namespace std;

Companion::Companion()
{
    name_ = "";
    fullness_ = 50;
}

Companion::Companion(string name)
{
    name_ = name;
    fullness_ = 50;
}

string Companion::getName()
{
    return name_;
}

int Companion::getFullness()
{
    return fullness_;
}

int Companion::setFullness(int lost_fullness)
{
    fullness_ -= lost_fullness;
    return fullness_;
}