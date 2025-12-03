#ifndef SFUI_LAYOUT_INTERFACE_HPP
#define SFUI_LAYOUT_INTERFACE_HPP

#include <vector>
#include "../widget.hpp"

namespace sfui {
	class Layout {
	private:
		std::vector<Widget*> m_controls;
		sf::Vector2f m_size;
		sf::Vector2f m_position;
		bool m_is_hidden;

	public:
		Layout(sf::Vector2f size, sf::Vector2f position = {0, 0}, bool hide = false)
			: m_size(size), m_position(position), m_is_hidden(hide) {}

		void setSize(sf::Vector2f size);
		void setSizeX(float size_x);
		void setSizeY(float size_y);
		void setPosition(sf::Vector2f position);
		void setPositionX(float position_x);
		void setPositionY(float position_y);
		sf::Vector2f getSize();
		sf::Vector2f getPosition();
		bool isHidden();
		std::vector<Widget*> getControls();

		void hideLayout(bool flag);
		void add(Widget* widget);
		void add(const std::vector<Widget*> controls);
		void remove(Widget* control);
		void remove(const std::vector<Widget*> controls);

		virtual void update() = 0;
		void draw(sf::RenderWindow* wnd);
		void processEvents(const sf::Event& event);
	};
}
#endif // !SFUI_LAYOUT_INTERFACE_HPP