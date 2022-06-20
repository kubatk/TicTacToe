#include "classes/Field.h"
#include <SFML/Graphics.hpp>

Field::Field() {
    mark_as_winner = false;
    x_pos = y_pos = -1;
    owner = nullptr;

    button.setFillColor(sf::Color::White);
    button.setOutlineThickness(1.f);
    button.setOutlineColor(sf::Color::Black);
}

Field::~Field() {
    delete owner;
}

int Field::get_x() const {
    return x_pos;
}

int Field::get_y() const {
    return y_pos;
}

Player* Field::get_owner() {
    return owner;
}

void Field::mark() {
    mark_as_winner = true;
}

void Field::unmark() {
    mark_as_winner = false;
}

bool Field::is_marked() {
    return mark_as_winner;
}

void Field::setpos(int x, int y) {
    x_pos = x;
    y_pos = y;
}

void Field::set_owner(Player* new_owner) {
    owner = new_owner;
}

void Field::draw(sf::RenderWindow& window) {
    window.draw(button);
}

bool Field::isMouseOver(sf::RenderWindow& window) {
    int mouseX = sf::Mouse::getPosition(window).x;
    int mouseY = sf::Mouse::getPosition(window).y;

    float btnPosX = button.getPosition().x;
    float btnPosY = button.getPosition().y;

    float btnWidth = btnPosX + button.getLocalBounds().width;
    float btnHeight = btnPosY + button.getLocalBounds().height;

    return (mouseX > btnPosX && mouseX < btnWidth&& mouseY < btnHeight&& mouseY > btnPosY);
}