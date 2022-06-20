#pragma once
#include "Field.h"

class Board{
private:
    Field** field;
    const int size;
    sf::Texture sign_x, sign_o, win_x, win_o;
public:

    Board(const int n);
    ~Board();
    Field* get_field(const int x, const int y);
    void unmark_all();
    bool is_full();
    void draw_grid(sf::RenderWindow& window);
    Field* get_clicked_field(sf::RenderWindow& window);
};
