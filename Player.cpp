#include "classes/Player.h"

Player::Player(char symbol, bool is_ai) {
    this->symbol = symbol;
    this->ai = is_ai;
}

char Player::get_symbol()
{
    return symbol;
}

bool Player::is_ai()
{
    return ai;
}
