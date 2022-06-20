#include "classes/Game.h"
#include <SFML/Graphics.hpp>

int Game::look_for_win(int need_to_win) {
    if (need_to_win == 0) need_to_win = length;
    int counter = 0;
    Player* counted_player = nullptr;
    //check by rows
    for (int row = 0; row < size; row++) {
        counter = 0;
        board->unmark_all();
        for (int column = 0; column < size; column++) {

            //reset counter
            if (board->get_field(row, column)->get_owner() == nullptr || board->get_field(row, column)->get_owner() != counted_player) {
                counter = 0;
                board->unmark_all();
            }

            //increase counter
            if (board->get_field(row, column)->get_owner() == players[0]) {
                counted_player = players[0];
                counter++;
                board->get_field(row, column)->mark();
            }
            if (board->get_field(row, column)->get_owner() == players[1]) {
                counted_player = players[1];
                counter++;
                board->get_field(row, column)->mark();
            }

            //check if counter get minimal value
            if (counter >= need_to_win) {
                winner = counted_player;
                finished = true;
                return 1;
            }
        }
    }

    //check by columns
    for (int column = 0; column < size; column++) {
        counter = 0;
        board->unmark_all();
        for (int row = 0; row < size; row++) {

            //reset counter
            if (board->get_field(row, column)->get_owner() == nullptr || board->get_field(row, column)->get_owner() != counted_player) {
                counter = 0;
                board->unmark_all();
            }

            //increase counter
            if (board->get_field(row, column)->get_owner() == players[0]) {
                counted_player = players[0];
                counter++;
                board->get_field(row, column)->mark();
            }
            if (board->get_field(row, column)->get_owner() == players[1]) {
                counted_player = players[1];
                counter++;
                board->get_field(row, column)->mark();
            }

            //check if counter get requested value
            if (counter >= need_to_win) {
                winner = counted_player;
                finished = true;
                return 1;
            }
        }
    }

    //check by diagonal ( \ )
    int x, y, i;
    for (i = 0; i < size; i++) {
        counter = 0;
        board->unmark_all();
        for (x = 0, y = size - 1 - i; x <= i; x++, y++) {
            //reset counter
            if (board->get_field(x, y)->get_owner() == nullptr || board->get_field(x, y)->get_owner() != counted_player) {
                counter = 0;
                board->unmark_all();
            }

            //increase counter
            if (board->get_field(x, y)->get_owner() == players[0]) {
                counted_player = players[0];
                counter++;
                board->get_field(x, y)->mark();
            }
            if (board->get_field(x, y)->get_owner() == players[1]) {
                counted_player = players[1];
                counter++;
                board->get_field(x, y)->mark();
            }

            //check if counter get requested value
            if (counter >= need_to_win) {
                winner = counted_player;
                finished = true;
                return 1;
            }
        }

    }
    for (i = size - 1; i > 0; i--) {
        counter = 0;
        board->unmark_all();
        for (x = size - i, y = 0; y < i; x++, y++) {
            //reset counter
            if (board->get_field(x, y)->get_owner() == nullptr || board->get_field(x, y)->get_owner() != counted_player) {
                counter = 0;
                board->unmark_all();
            }

            //increase counter
            if (board->get_field(x, y)->get_owner() == players[0]) {
                counted_player = players[0];
                counter++;
                board->get_field(x, y)->mark();
            }
            if (board->get_field(x, y)->get_owner() == players[1]) {
                counted_player = players[1];
                counter++;
                board->get_field(x, y)->mark();
            }

            //check if counter get requested value
            if (counter >= need_to_win) {
                winner = counted_player;
                finished = true;
                return 1;
            }
        }

    }

    //check by diagonal ( / )
    for (i = 0; i < size; i++) {
        counter = 0;
        board->unmark_all();
        for (x = i, y = 0; x >= 0; x--, y++) {
            //reset counter
            if (board->get_field(x, y)->get_owner() == nullptr || board->get_field(x, y)->get_owner() != counted_player) {
                counter = 0;
                board->unmark_all();
            }

            //increase counter
            if (board->get_field(x, y)->get_owner() == players[0]) {
                counted_player = players[0];
                counter++;
                board->get_field(x, y)->mark();
            }
            if (board->get_field(x, y)->get_owner() == players[1]) {
                counted_player = players[1];
                counter++;
                board->get_field(x, y)->mark();
            }

            //check if counter get requested value
            if (counter >= need_to_win) {
                winner = counted_player;
                finished = true;
                return 1;
            }
        }
    }
    for (i = size - 1; i > 0; i--) {
        counter = 0;
        board->unmark_all();
        for (x = size - 1, y = size - i; y < size; x--, y++) {
            //reset counter
            if (board->get_field(x, y)->get_owner() == nullptr || board->get_field(x, y)->get_owner() != counted_player) {
                counter = 0;
                board->unmark_all();
            }

            //increase counter
            if (board->get_field(x, y)->get_owner() == players[0]) {
                counted_player = players[0];
                counter++;
                board->get_field(x, y)->mark();
            }
            if (board->get_field(x, y)->get_owner() == players[1]) {
                counted_player = players[1];
                counter++;
                board->get_field(x, y)->mark();
            }

            //check if counter get requested value
            if (counter >= need_to_win) {
                winner = counted_player;
                finished = true;
                return 1;
            }
        }
    }



    //win not found
    board->unmark_all();
    return 0;
}