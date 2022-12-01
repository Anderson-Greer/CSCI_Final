#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "Game.h"

using namespace std;

bool Game::getGameOver() {
    return game_over_;
}

bool Game::setGameOver(bool status) {
    game_over_ = status;
    return game_over_;
}
/*
    1. Check to make sure movement is valid
    2. If direction is valid, move the party using the map class and it's current position
    3. North: increase row by 1, South: decrease row by 1, West: increase column by 1, East: decrease column by 1
    4. After movement, each party member has a 20% chance of losing 1 fullness point
*/
void Game::move(char direction) { // handles the movement of the party

}

/*
>>>>>>> Stashed changes
=======
>>>>>>> a843ca4f33c8294889845ecbb08a58b85c27c916
    1. Check if space is already explored or not
    2. If it is, tell player to choose something else, if not, continue function
    3. Run random number, 10% chance player finds key, 20% chance player finds treasure, 20% chance player has to fight random monster
    4. 50% chance party member's fullness drops by 1 point
*/
void Game::investigate() { // handles the investigation of a space

}

/*
    1. Given monster, calculate if party defeats it or not
    2. If fight is won, party gains 10 * diff of monster gold pieces and 5 * diff of monster kg of ingredients
    3. 10% chance monster drops a key
    4. If monster is defeated, remove monster from list of possible monsters
    5. If party is defeated, they lose a quarter of gold reserves, 30kg of ingredients, and a chance that each party member dies
        (10% chance of death without armor, 5% with armor)
*/
// void Game::fight(Monster monster) { // handles picking a fight

// }

/*
    1. Check to see if cookware breaks while cooking given it's chance of breaking
    2. If it doesn't break, fullness gained = kg of ingredients / 5
*/
void Game::cookAndEat(Item, double) { // handles cooking and eating ingredients

}

/*
    1. Print message stating that the game ended
*/
void Game::giveUp() { // handles giving up

}
