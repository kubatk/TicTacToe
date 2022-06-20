#pragma once
#include <cstdlib>
#include "Player.h"
#include "Board.h"

class Game{
private:
    bool finished;
    const int size;
    const int length;
    Player* winner;
    Player* players[2];
    Board *board;
public:
    Game(const int field_size, const int req_length, bool is_ai);
    ~Game();
    Board* get_board();
    Player* get_winner();
    void set_field_owner(int x, int y, char sign);
    void remove_field_owner(int x, int y);
    Player* get_player_by_sign(char sign);
    bool is_finished();
        
    int look_for_win(int need_to_win = 0);

    Field* random_empty_field();

    Field* get_ai_move(int difficulty);
};
