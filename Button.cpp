#include "classes/Button.h"
#include <SFML/Graphics.hpp>

Button::Button() {
	button.setFillColor(sf::Color::White);
}

Button::Button(sf::Vector2f pos, sf::Vector2f size) {
	button.setPosition(pos.x, pos.y);
	button.setSize({ size.x, size.y });
}

bool Button::isMouseOver(sf::RenderWindow& window) {
	int mouseX = sf::Mouse::getPosition(window).x;
	int mouseY = sf::Mouse::getPosition(window).y;

	float btnPosX = button.getPosition().x;
	float btnPosY = button.getPosition().y;

	float btnWidth = btnPosX + button.getLocalBounds().width;
	float btnHeight = btnPosY + button.getLocalBounds().height;

	return (mouseX > btnPosX && mouseX < btnWidth&& mouseY < btnHeight&& mouseY > btnPosY);
}

void Button::draw_button(sf::RenderWindow& window) {
	window.draw(button);
	text.draw_text(window);
}

void Button::set_position(sf::Vector2f pos) {
	button.setPosition(pos.x, pos.y);
}

void Button::set_size(sf::Vector2f btn_size) {
	button.setSize({ btn_size.x, btn_size.y });
}

void Button::set_texture(const char* filename) {
	texture.loadFromFile(filename);
	button.setTexture(&texture);
}

void Button::set_border(int width, sf::Color color) {
	button.setOutlineThickness(width);
	button.setOutlineColor(color);
}

void Button::set_display_text(std::string new_text, int size) {

	text.set_display_text(new_text);
	text.set_size(size);

	float posX = button.getPosition().x + ((button.getLocalBounds().width - 2 * button.getOutlineThickness()) - text.getLocalBounds().width) / 2;
	float posY = -3 + button.getPosition().y + ((button.getLocalBounds().height - 2 * button.getOutlineThickness()) - text.getLocalBounds().height) / 2;

	text.set_position(posX, posY);

}

void Button::set_color(int r, int g, int b) {
	button.setFillColor(sf::Color(r, g, b, 255));
}