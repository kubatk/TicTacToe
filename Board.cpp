#include "classes/Board.h"
#include <SFML/Graphics.hpp>

Board::Board(const int n) :size(n) {
    field = new Field * [n];
    for (int i = 0; i < n; ++i)
        field[i] = new Field[n];
    int x, y;
    for (x = 0; x < n; x++) {
        for (y = 0; y < n; y++) {
            field[x][y].setpos(x, y);
        }
    }
    sign_x.loadFromFile("images/x.png");
    sign_o.loadFromFile("images/o.png");
    win_x.loadFromFile("images/win_x.png");
    win_o.loadFromFile("images/win_o.png");
}

Board::~Board() {
    delete[] field;
}

Field* Board::get_field(const int x, const int y) {
    return &(field[x][y]);
}

void Board::unmark_all() {
    int x, y;
    for (x = 0; x < size; x++) {
        for (y = 0; y < size; y++) {
            field[x][y].unmark();
        }
    }
}

bool Board::is_full() {
    int x, y;
    for (x = 0; x < size; x++) {
        for (y = 0; y < size; y++) {
            if (field[x][y].get_owner() == nullptr) return false;
        }
    }
    return true;
}

void Board::draw_grid(sf::RenderWindow& window) {
    int x, y;
    float posX, posY;

    float lr_margin = 50;

    float btn_size = (float)((window.getSize().x - (2 * lr_margin)) / size) - 2 * 1;

    float top_margin = window.getSize().y - lr_margin - (btn_size + 2) * size;

    posX = lr_margin;
    posY = top_margin;

    for (x = 0; x < size; x++) {
        for (y = 0; y < size; y++) {
            field[x][y].button.setSize({ btn_size, btn_size });
            field[x][y].button.setPosition(posX, posY);

            if (field[x][y].get_owner() != nullptr) {
                if (field[x][y].get_owner()->get_symbol() == 'o') {
                    if (field[x][y].is_marked()) field[x][y].button.setTexture(&win_o);
                    else field[x][y].button.setTexture(&sign_o);
                }
                else {
                    if (field[x][y].is_marked()) field[x][y].button.setTexture(&win_x);
                    else field[x][y].button.setTexture(&sign_x);
                }
            }

            field[x][y].draw(window);
            posY += btn_size + 2;
        }
        posX += btn_size + 2;
        posY = top_margin;
    }
}

Field* Board::get_clicked_field(sf::RenderWindow& window) {
    int x, y;
    for (y = 0; y < size; y++) {
        for (x = 0; x < size; x++) {
            if (field[x][y].isMouseOver(window)) {
                return &(field[x][y]);
            }
        }
    }
    return nullptr;
}