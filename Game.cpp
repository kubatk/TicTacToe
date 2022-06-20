#include "classes/Game.h"
#include <SFML/Graphics.hpp>

Game::Game(const int field_size, const int req_length, bool is_ai) : size(field_size), length(req_length) {
    finished = false;
    board = new Board(field_size);
    winner = nullptr;
    players[0] = new Player('o', false);
    players[1] = new Player('x', is_ai);
}

Game::~Game() {
    delete winner;
    delete board;
}

Board* Game::get_board() {
    return board;
}

Player* Game::get_winner() {
    return winner;
}

void Game::set_field_owner(int x, int y, char sign) {
    Player* new_owner;

    if (players[0]->get_symbol() == sign) new_owner = players[0];
    else if (players[1]->get_symbol() == sign) new_owner = players[1];
    else return;

    board->get_field(x, y)->set_owner(new_owner);
}

void Game::remove_field_owner(int x, int y) {
    board->get_field(x, y)->set_owner(nullptr);
}

Player* Game::get_player_by_sign(char sign) {
    if (players[0]->get_symbol() == sign) return players[0];
    else if (players[1]->get_symbol() == sign) return players[1];
    else return nullptr;
}
bool Game::is_finished() {
    return finished;
}