#ifndef SFUI_UTILS_HPP
#define SFUI_UTILS_HPP

#include <memory>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>

namespace sfui {
	bool isMouseOver(const sf::RectangleShape& rect, const sf::Vector2f& mouse_position);
	bool isMouseOver(const sf::CircleShape& circle, const sf::Vector2f& mouse_position);
}
#endif // !SFUI_UTILS_HPP