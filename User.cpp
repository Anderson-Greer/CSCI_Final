#include <string>
#include "User.h"

using namespace std;

User::User() {
    name_ = ""; // name of player
    rooms_cleared_ = 0; // number of rooms that have been cleared
    armor_ = false;
    keys_ = 0;
}

User::User(string name) {
    name_ = name;
    rooms_cleared_ = 0;
    armor_ = false;
    keys_ = 0;
}

string User::getName() {
    return name_;
}

vector<Item> User::getIngredients() {
    return ingredients_;
}

vector<Weapon> User::getWeapons() {
    return weapons_;
}

bool User::getArmor() {
    return armor_;
}

vector<Item> User::getCookware() {
    return cookware_;
}

vector<Item> User::getSellingTreasures() {
    return selling_treasures_;
}

int User::getRoomsCleared() {
    return rooms_cleared_;
}

int User::getNumKeys() {
    return keys_;
}

vector<Item> User::addIngredient(Item item) { // add ingredient to ingredients vector
    ingredients_.push_back(item);
    return ingredients_;
}

vector<Weapon> User::addWeapon(Weapon weapon) { // add weapon to weapons vector
    weapons_.push_back(weapon);
    return weapons_;
}

bool User::setArmor(bool armor_val) { // changes armor value of player (true if player has armor, false if not)
    armor_ = armor_val;
    return armor_;
}

vector<Item> User::addCookware(Item cookware) { // add cookware to cookware vector
    cookware_.push_back(cookware);
    return cookware_;
}

int User::addKey() { // adds a key to key count and returns the new number of keys
    keys_++;
    return keys_;
}

/*
    1. Loop through vector
    2. Compare the damage of each weapon to the next weapon in the vector
    3. If the current Weapon has more damage, move on to next iteration of loop
    4. If the second Weapon has more damage, swap the two
    5. Continue iterating through for loop until the vector is in order
*/
void User::bubbleSortWeapons(vector<Weapon> weapons) {

}
