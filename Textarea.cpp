#include "classes/Textarea.h"
#include <SFML/Graphics.hpp>

Textarea::Textarea() {
	comici.loadFromFile("fonts/comici.ttf");
	text.setFont(comici);
	text.setCharacterSize(12);
	text.setFillColor(sf::Color::Black);
}

Textarea::Textarea(sf::Vector2f pos, int size, std::string new_text) {
	comici.loadFromFile("fonts/comici.ttf");
	text.setFont(comici);
	text.setString(new_text);
	text.setPosition(pos.x, pos.y);
	text.setCharacterSize(size);
	text.setFillColor(sf::Color::Black);
}

void Textarea::set_position(float pos_x, float pos_y) {
	text.setPosition({ pos_x, pos_y });
}

void Textarea::center() {
	int width = text.getLocalBounds().width;
	text.setPosition({ (float)((650 - width) / 2), text.getPosition().y });
}

void Textarea::set_display_text(std::string new_text) {
	text.setString(new_text);
}

void Textarea::draw_text(sf::RenderWindow& window) {
	window.draw(text);
}

void Textarea::set_size(int size) {
	text.setCharacterSize(size);
}

sf::FloatRect Textarea::getLocalBounds() {
	return text.getLocalBounds();
}