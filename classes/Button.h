#pragma once
#include <SFML/Graphics.hpp>
#include "Textarea.h"

class Button {
private:
	sf::RectangleShape button;
	sf::Texture texture;
	Textarea text;

public:
	Button();
	Button(sf::Vector2f pos, sf::Vector2f size);
	bool isMouseOver(sf::RenderWindow& window);
	void draw_button(sf::RenderWindow& window);
	void set_position(sf::Vector2f pos);
	void set_size(sf::Vector2f btn_size);
	void set_texture(const char* filename);
	void set_border(int width, sf::Color color);
	void set_display_text(std::string new_text, int size);
	void set_color(int r, int g, int b);
};