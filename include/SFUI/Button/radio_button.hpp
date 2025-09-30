#ifndef SFUI_RADIO_BUTTON_HPP
#define SFUI_RADIO_BUTTON_HPP

#include "button_interface.hpp"
#include "../widget.hpp"

namespace sfui {
	class RadioButton: public Widget, IButton {
	friend class Canvas;
	friend class Window;
	private:
		sf::CircleShape m_circle;
		sf::Color m_fill_color;
		sf::Color m_outline_color;

		bool m_is_hovered;
		bool m_is_pressed;
		bool m_is_active;
		std::function<void()> m_on_pressed_callback;
		std::function<void()> m_on_hover_callback;
		std::function<void()> m_on_released_callback;

	public:
		RadioButton(bool active = false, std::function<void()> on_pressed_callback = nullptr): m_is_active(active), m_is_pressed(false), m_is_hovered(false),
			m_on_pressed_callback(on_pressed_callback), m_on_hover_callback(nullptr), m_on_released_callback(nullptr),
			m_fill_color(sf::Color::White), m_outline_color(sf::Color::Black) {
			m_circle.setRadius(8);
			m_circle.setOutlineThickness(5);
			m_circle.setOutlineColor(m_outline_color);
			m_circle.setFillColor((m_is_active) ? m_fill_color : m_outline_color);
		}
		
		/// <summary>
		/// Set Button enbled or disabled
		/// </summary>
		/// <param name="flag"></param>
		void setStatus(bool flag);

		/// <summary>
		/// Set position by x and y
		/// </summary>
		/// <param name="position"></param>
		void setPosition(sf::Vector2f position) override;

		/// <summary>
		/// Set position by x
		/// </summary>
		/// <param name="position_x"></param>
		void setPositionX(float position_x);

		/// <summary>
		/// Set position by y
		/// </summary>
		/// <param name="position_y"></param>
		void setPositionY(float position_y);

		/// <summary>
		/// Set radius of the Button
		/// </summary>
		/// <param name="size"></param>
		void setRadius(float size);

		/// <summary>
		/// Set Button body color
		/// </summary>
		/// <param name="color"></param>
		void setFillColor(sf::Color color);

		/// <summary>
		/// Set on pressed callback
		/// </summary>
		/// <param name="on_pressed_callback"></param>
		void setOnPressedCallback(std::function<void()> on_pressed_callback) override;

		/// <summary>
		/// Set on hover callback
		/// </summary>
		/// <param name="on_hover_callback"></param>
		void setOnHoverCallback(std::function<void()> on_hover_callback) override;

		/// <summary>
		/// Set on released callback
		/// </summary>
		/// <param name="on_released_callback"></param>
		void setOnReleasedCallback(std::function<void()> on_released_callback) override;

		/// <summary>
		/// Return the position of the Button
		/// </summary>
		/// <returns>sf::Vector2f</returns>
		sf::Vector2f getPosition() override;

		/// <summary>
		/// Return the radius of the Button
		/// </summary>
		/// <returns>float</returns>
		float getSize();

		/// <summary>
		/// Check if the Button is active
		/// </summary>
		/// <returns>bool</returns>
		bool isActive();

	private:
		void processEvents(const sf::Event& event) override;
		void draw(sf::RenderWindow* wnd) override;

		/* EVENTS */
		void onHover();
		void onPressed();
		void onReleased();

		/* UTILS */
		bool isMouseOver(sf::Vector2f mouse_pos);
	};
}
#endif // !SFUI_RADIO_BUTTON_HPP