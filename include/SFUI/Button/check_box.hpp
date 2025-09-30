#ifndef SFUI_CHECK_BOX_HPP
#define SFUI_CHECK_BOX_HPP

#include "button_interface.hpp"
#include "../widget.hpp"

namespace sfui {
	class CheckBox: public virtual Widget, IButton {
	friend class Canvas;
	friend class Window;
	private:
		sf::RectangleShape m_rect;
		sf::Color m_fill_color;
		sf::Color m_outline_color;

		bool m_is_hovered;
		bool m_is_pressed;
		bool m_is_active;
		std::function<void()> m_on_pressed_callback;
		std::function<void()> m_on_hover_callback;
		std::function<void()> m_on_released_callback;

	public:
		CheckBox(bool active = false, std::function<void()> on_pressed_callback = nullptr): m_is_active(active), m_is_pressed(false), m_is_hovered(false),
			m_on_pressed_callback(on_pressed_callback), m_on_hover_callback(nullptr), m_on_released_callback(nullptr),
			m_fill_color(sf::Color::White), m_outline_color(sf::Color::Black) {
			m_rect.setSize({ 15, 15 });
			m_rect.setOutlineThickness(5);
			m_rect.setOutlineColor(m_outline_color);
			m_rect.setFillColor((m_is_active) ? m_fill_color : m_outline_color);
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
		/// Set size by x and y
		/// </summary>
		/// <param name="size"></param>
		void setSize(sf::Vector2f size);

		/// <summary>
		/// Set position by x
		/// </summary>
		/// <param name="size_x"></param>
		void setSizeX(float size_x);

		/// <summary>
		/// Set size by y
		/// </summary>
		/// <param name="size_y"></param>
		void setSizeY(float size_y);

		/// <summary>
		/// Set rotation in sf::Angle
		/// </summary>
		/// <param name="angle"></param>
		void setRotation(sf::Angle angle);

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
		/// Return the size of the Button
		/// </summary>
		/// <returns>sf::Vector2f</returns>
		sf::Vector2f getSize();

		/// <summary>
		/// Return the rotation of the Button
		/// </summary>
		/// <returns>sf::Angle</returns>
		sf::Angle getRotation();

		/// <summary>
		/// Check if Button is active
		/// </summary>
		/// <returns>bool</returns>
		bool isActive();

	private:
		void processEvents(const sf::Event& event) override;
		void draw(sf::RenderWindow* wnd) override;

		// Events
		void onHover();
		void onPressed();
		void onReleased();

		// Utils
		bool isMouseOver(sf::Vector2f mouse_pos);
	};
}
#endif // !SFUI_CHECK_BOX_HPP