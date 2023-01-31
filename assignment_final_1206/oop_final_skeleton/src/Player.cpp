#include "Player.h"

Player::Player(int x, int y) : Object(x, y) {}

char Player::getSymbol() {
    return 'P';
}

int Player::getColor() {
    return COLOR_SET_PLAYER;
}