#ifndef SFUI_BUTTON_INTERFACE_HPP
#define SFUI_BUTTON_INTERFACE_HPP

#include <functional>
#include "SFML/Graphics.hpp"

namespace sfui {
	class IButton {
	protected:
		bool m_is_hovered;
		bool m_is_pressed;
		bool m_is_active;
		std::function<void()> m_on_pressed_callback;
		std::function<void()> m_on_hover_callback;
		std::function<void()> m_on_released_callback;

	protected:
		virtual void processEvents(const sf::Event& event) = 0;
		virtual void setOnPressedCallback(std::function<void()> on_pressed_callback) = 0;
		virtual void setOnHoverCallback(std::function<void()> on_hover_callback) = 0;
		virtual void setOnReleasedCallback(std::function<void()> on_released_callback) = 0;
	};
}
#endif // !SFUI_BUTTON_INTERFACE_HPP