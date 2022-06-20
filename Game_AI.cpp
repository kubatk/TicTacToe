#include "classes/Game.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Field* Game::random_empty_field() {
    if (finished) return nullptr;
    int x, y;
    Field* field;
    srand(time(NULL));
    while (true) {
        x = rand() % size;
        y = rand() % size;
        field = board->get_field(x, y);
        if (field->get_owner() == nullptr) return field;
    }
}

Field* Game::get_ai_move(int difficulty) {

    int x, y, rate = 0, i, j, win, win_points, block_points, win_diff, block_diff;
    int minimal = 100000;

    win = length;

    win_points = difficulty == 2 ? 0 : 1005;
    win_diff = difficulty == 2 ? 0 : 15;
    block_points = 1000;
    block_diff = 5;



    //allocate rating table
    int** rating = new int* [size];
    for (i = 0; i < size; ++i) {
        rating[i] = new int[size];
    }
    //fill array with zeros
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            rating[i][j] = 0;
        }
    }

    //give points value to the field
    for (win = length; win > 1; win--) {

        for (i = 0; i < size; i++) {
            for (j = 0; j < size; j++) {


                if (board->get_field(i, j)->get_owner() == nullptr) {

                    //Try to put AI's symbol
                    set_field_owner(i, j, 'x');
                    if (look_for_win(win)) {
                        rating[i][j] += win_points;
                    }
                    finished = false;
                    board->unmark_all();
                    remove_field_owner(i, j);

                    //Try to put user's symbol
                    set_field_owner(i, j, 'o');
                    if (look_for_win(win)) {
                        rating[i][j] += block_points;
                    }
                    finished = false;
                    board->unmark_all();
                    remove_field_owner(i, j);
                }

            }
        }

        win_points -= win_diff;
        block_points -= block_diff;

    }

    //Look for most profitable field
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (rating[i][j] > rate) {
                rate = rating[i][j];
                x = i;
                y = j;
            }
        }
    }

    //Find lowest value
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (rating[i][j] < minimal && board->get_field(i, j)->get_owner() == nullptr) {
                minimal = rating[i][j];
            }
        }
    }

    //cleanup
    for (i = 0; i < size; ++i) {
        delete[] rating[i];
    }
    delete[] rating;
    rating = NULL;

    //return result
    if (rate == minimal) return random_empty_field();
    else return board->get_field(x, y);
}