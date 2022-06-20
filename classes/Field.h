#pragma once
#include "Player.h"
#include <SFML/Graphics.hpp>

class Field{
private:
    int x_pos;
    int y_pos;
    char sign='\0';
    bool mark_as_winner;
    Player* owner;
public:
    sf::RectangleShape button;

    Field();
    ~Field();
    int get_x() const;
    int get_y() const;
    Player* get_owner();
    void mark();
    void unmark();
    bool is_marked();
    void setpos(int x, int y);
    void set_owner(Player* new_owner);
    void draw(sf::RenderWindow& window);
    bool isMouseOver(sf::RenderWindow& window);
};
