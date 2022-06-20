#pragma once
#include <SFML/Graphics.hpp>

class Textarea {
private:
	sf::Text text;
	sf::Font comici;
public:
	Textarea();
	Textarea(sf::Vector2f pos, int size, std::string new_text);
	void set_position(float pos_x, float pos_y);
	void center();
	void set_display_text(std::string new_text);
	void draw_text(sf::RenderWindow& window);
	void set_size(int size);
	sf::FloatRect getLocalBounds();
};