#include <string>
#include "User.h"

using namespace std;

User::User() {
    name_ = ""; // name of player
    rooms_cleared_ = 0; // number of rooms that have been cleared
    armor_ = 0;
    keys_ = 0;
    fullness_ = 50;
    gold_ = 100;
    ingredients_ = 0;
    anger_level_ = 0;
}

User::User(string name) {
    name_ = name;
    rooms_cleared_ = 0;
    armor_ = 0;
    keys_ = 0;
    fullness_ = 50;
    gold_ = 100;
    ingredients_ = 0;
    anger_level_ = 0;
}

string User::getName() {
    return name_;
}

int User::getIngredients() {
    return ingredients_;
}

vector<Weapon> User::getWeapons() {
    return weapons_;
}

int User::getArmor() {
    return armor_;
}

vector<Item> User::getCookware() {
    return cookware_;
}

vector<Companion> User::getCompanions() {
    return companions_;
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

int User::getFullness() {
    return fullness_;
}

int User::getAngerLevel() {
    return anger_level_;
}

int User::getGold() {
    return gold_;
}

vector<Weapon> User::addWeapon(Weapon weapon) { // add weapon to weapons vector
    weapons_.push_back(weapon);
    return weapons_;
}

int User::setArmor(int armor_num) { // changes armor value of party
    armor_ = armor_num;
    return armor_;
}

vector<Item> User::addCookware(Item cookware) { // add cookware to cookware vector
    cookware_.push_back(cookware);
    return cookware_;
}

vector<Companion> User::addCompanion(Companion companion) { // add cookware to cookware vector
    companions_.push_back(companion);
    return companions_;
}

vector<Item> User::addTreasure(Item treasure) { // add treasure to treasures vector
    selling_treasures_.push_back(treasure);
    return selling_treasures_;
}

vector<Item> User::removeTreasure(int index) { // add treasure to treasures vector
    selling_treasures_.erase(selling_treasures_.begin() + index);
    return selling_treasures_;
}

int User::addKey() { // adds a key to key count and returns the new number of keys
    keys_++;
    return keys_;
}

int User::increaseRoomsCleared() { // increases the number of rooms cleared
    if(rooms_cleared_ >= 5)
        return -1;

    rooms_cleared_++;
    return rooms_cleared_;
}

int User::setFullness(int lost_fullness) {
    fullness_ -= lost_fullness;
    return fullness_;
}

int User::setAngerLevel(int level) {
    anger_level_ = level;
    return anger_level_;
}

int User::setGold(int gold) {
    gold_ = gold;
    return gold_;
}

int User::setIngredients(int ingredients) {
    ingredients_ = ingredients;
    return ingredients;
}

void User::runPlayerAction(Map map) {
    srand((unsigned) time(NULL));

    string input;
    cout << "\nPlease choose one of the following: " <<
            "\n  1. Move a single space in any direction, 20% chance fullness of any party member drops by 1." <<
            "\n  2. Investigate, explore an unexplored space. [10% chance you find a key, " <<
                "20% chance you find treasure, or 20% chance you must fight a random monster]" <<
            "\n  3. Pick a fight and cause a random monster to appear. Defeating a monster has a" <<
                " 10% chance of dropping a key." <<
            "\n  4. Cook and Eat using current ingredients and cookware." <<
            "\n  5. Give up and end the game." << endl;
    cin >> input;

    switch(stoi(input)) {
        case 1:
        {
            char direction;
            cout << "Enter a direction you would like to move [w for up, s for down," <<
                " a for left, and d for right]" << endl;
            cin >> direction;
            map.move(direction);

            int rand_num = 1 + rand() % 100;
            if(rand_num <= 20) {
                fullness_--;
                cout << "You lost 1 fullness from moving." << endl;
            }
            for(int i = 0; i < 4; i++) {
                rand_num = 1 + rand() % 100;
                if(rand_num <= 20) {
                    companions_.at(i).setFullness(companions_.at(i).getFullness() - 1);
                    cout << companions_.at(i).getName() << " lost 1 fullness from moving." << endl;
                }
            }
        }
    }
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
