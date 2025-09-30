#ifndef SFUI_BUTTON_HPP
#define SFUI_BUTTON_HPP

#include "button_interface.hpp"
#include "../Text/text.hpp"
#include "../widget.hpp"

namespace sfui {
	class Button: virtual public Widget, IButton {
	friend class Canvas;
	friend class Range;
	friend class Window;
	public:
		Text* text;

	private:
		sf::Texture* m_texture;
		sf::RectangleShape m_rect;
		sf::Color m_fill_color;
		sf::Color m_hover_color;
		bool m_is_hovered;
		bool m_is_pressed;
		bool m_is_hold;
		std::function<void()> m_on_pressed_callback; 
		std::function<void()> m_on_hover_callback;
		std::function<void()> m_on_released_callback;

		sf::Clock m_hold_timer;
		sf::Time m_hold_delay;

	public:
		Button(Text* text = nullptr, std::function<void()> callback = nullptr)
			: m_texture(nullptr), m_on_pressed_callback(callback), m_on_hover_callback(nullptr), m_on_released_callback(nullptr),
			m_is_pressed(false), m_is_hovered(false), m_is_hold(false),
			m_fill_color(sf::Color::White), m_hover_color(sf::Color::Green), text(text) {
			m_hold_delay = sf::seconds(0.15);
			m_rect.setSize({ 80, 30 });
			m_rect.setFillColor(m_fill_color);
			m_rect.setOutlineThickness(1);
			m_rect.setOutlineColor(sf::Color::Black);
			if(text) this->text->setFillColor(sf::Color::Black);
		}

		~Button() {
			delete text;
		}

		/// <summary>
		/// Set the position by x and y
		/// </summary>
		/// <param name="position"></param>
		void setPosition(sf::Vector2f position);

		/// <summary>
		/// Set the position only by x
		/// </summary>
		/// <param name="position_x"></param>
		void setPositionX(float position_x);

		/// <summary>
		/// Set the position only by y
		/// </summary>
		/// <param name="position_y"></param>
		void setPositionY(float position_y);

		/// <summary>
		/// Set size by x and y
		/// </summary>
		/// <param name="size"></param>
		void setSize(sf::Vector2f size);

		/// <summary>
		/// Set size only by x
		/// </summary>
		/// <param name="size_x"></param>
		void setSizeX(float size_x);

		/// <summary>
		/// Set size only by y
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
		/// Set hover color
		/// </summary>
		/// <param name="color"></param>
		void setHoverColor(sf::Color color);

		/// <summary>
		/// Set texture to the Button
		/// </summary>
		/// <param name="texture_path"></param>
		void setTexture(const std::string& texture_path);

		/// <summary>
		/// Set outline border size
		/// </summary>
		/// <param name="thickness"></param>
		void setOutlineThickness(float thickness);

		/// <summary>
		/// Set borser color
		/// </summary>
		/// <param name="color"></param>
		void setOutlineColor(sf::Color color);

		/// <summary>
		/// Set on pressed callback
		/// </summary>
		/// <param name="on_pressed_callback"></param>
		void setOnPressedCallback(std::function<void()> on_pressed_callback);

		/// <summary>
		/// Set on hover callback
		/// </summary>
		/// <param name="on_hover_callback"></param>
		void setOnHoverCallback(std::function<void()> on_hover_callback);

		/// <summary>
		/// Set on released callback
		/// </summary>
		/// <param name="on_released_callback"></param>
		void setOnReleasedCallback(std::function<void()> on_released_callback);

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
		/// Check if Button is pressed
		/// </summary>
		/// <returns>bool</returns>
		bool isPressed();

		/// <summary>
		/// Check if Button is hovered
		/// </summary>
		/// <returns>bool</returns>
		bool isHovered();

	private:
		void draw(sf::RenderWindow* wnd) override;
		void processEvents(const sf::Event& event) override;

		/* EVENTS */
		void onHover();
		void onPressed();
		void onReleased();
		void onHold();

		/* UTILS */
		void centrateText();
		bool isMouseOver(sf::Vector2f mouse_pos);
	};
}
#endif // !SFUI_BUTTON_HPP