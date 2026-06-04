#include "../../../include/SFUI/utils.hpp"

bool sfui::isMouseOver(const sf::RectangleShape& rect, const sf::Vector2f& mouse_position) {
	return rect.getGlobalBounds().contains(mouse_position);
}

bool sfui::isMouseOver(const sf::CircleShape& circle, const sf::Vector2f& mouse_position) {
	return circle.getGlobalBounds().contains(mouse_position);
}