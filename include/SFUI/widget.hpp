#ifndef SFUI_WIDGET_HPP
#define SFUI_WIDGET_HPP

#include "SFML/Graphics.hpp"

namespace sfui {
	class Widget {
	friend class Window;
	friend class Layout;
	friend class DefaultLayout;
	private:
		sf::Vector2f m_base_position;
		bool m_is_drawable;

	private:
		virtual void draw(sf::RenderWindow* wnd) = 0;

	public:
		virtual void setPosition(sf::Vector2f position) = 0;
		virtual sf::Vector2f getPosition() = 0;
		virtual sf::Vector2f getSize() = 0;
	};
}
#endif // !SFUI_WIDGET_HPP