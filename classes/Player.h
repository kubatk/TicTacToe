#pragma once

class Player{
private:
    char symbol;
    bool ai;
public:
    Player(char symbol, bool is_ai = false);
    char get_symbol();
    bool is_ai();
};