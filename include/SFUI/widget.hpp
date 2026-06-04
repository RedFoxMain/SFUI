#ifndef SFUI_WIDGET_HPP
#define SFUI_WIDGET_HPP

#include <memory>
#include <SFML/Graphics.hpp>
#include "utils.hpp"

namespace sfui {
	class Widget: public sf::Drawable {
	public:
		Widget() = default;
		~Widget() = default;

		virtual void hide(bool hidden) = 0;
		virtual void setPosition(sf::Vector2f position) = 0;
		virtual sf::Vector2f getPosition() = 0;
		virtual sf::Vector2f getSize() = 0;
	};

	class Container: public sf::Drawable {
	public:
		virtual void addChild(std::shared_ptr<Widget> widget) = 0;
		virtual void addChild(std::vector<std::shared_ptr<Widget>> widgets) = 0;
		virtual void removeChild(std::shared_ptr<Widget> widget) = 0;
		virtual void removeChild(std::vector<std::shared_ptr<Widget>> widgets) = 0;

	protected:
		static bool widgetInBounds(std::shared_ptr<Widget> widget, const sf::Vector2u& window_size) {
			sf::Vector2f widget_pos = widget->getPosition();
			sf::Vector2f widget_size = widget->getSize();
			return (widget_pos.x >= 0) &&
				(widget_pos.x + widget_size.x <= window_size.x) &&
				(widget_pos.y >= 0) &&
				(widget_pos.y + widget_size.y <= window_size.y);
		}

		static void setWidgetInBounds(std::shared_ptr<Widget> widget, const sf::Vector2u& window_size) {
			sf::Vector2f widget_pos = widget->getPosition();
			sf::Vector2f widget_size = widget->getSize();
			if (widget_pos.x < 0.f)
				widget->setPosition({ 0.f, widget_pos.y });
			else if (widget_pos.x + widget_size.x > window_size.x)
				widget->setPosition({ window_size.x - widget_size.x, widget_pos.y });
			else if (widget_pos.y < 0.f)
				widget->setPosition({ widget_pos.x, 0.f });
			else if (widget_pos.y + widget_size.y > window_size.y)
				widget->setPosition({ widget_pos.x, window_size.y - widget_size.y });
		}
	};

	class Processable {
	public:
		virtual void processEvents(const sf::Event& event) = 0;
	};

	class Updatable {
	public:
		virtual void update(const sf::RenderWindow& window) = 0;
	};
}
#endif // !SFUI_WIDGET_HPP