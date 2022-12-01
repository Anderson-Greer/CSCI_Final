#include <string>
#include <iostream>
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

void Game::giveUp() { // handles giving up

}
