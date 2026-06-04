#ifndef SFUI_RADIO_BUTTON_HPP
#define SFUI_RADIO_BUTTON_HPP

#include "../widget.hpp"
#include "button_interface.hpp"

namespace sfui {
	class RadioButton: public Widget, public Updatable, public Processable, ButtonBase {
	private:
		sf::CircleShape m_circle;
		sf::Color m_fill_color;
		sf::Color m_outline_color;

		bool m_is_hovered;
		bool m_is_pressed;
		bool m_is_active;
		bool m_is_enabled;
		bool m_is_hidden;
		std::function<void()> m_on_pressed_callback;
		std::function<void()> m_on_hover_callback;
		std::function<void()> m_on_released_callback;

	public:
		RadioButton(bool active = false, std::function<void()> on_pressed_callback = nullptr)
			: m_is_active(active), m_is_pressed(false), m_is_hovered(false), m_is_hidden(false),
			m_on_pressed_callback(on_pressed_callback), m_on_hover_callback(nullptr), m_on_released_callback(nullptr),
			m_fill_color(sf::Color::White), m_outline_color(sf::Color::Black) {
			m_circle.setRadius(8);
			m_circle.setOutlineThickness(5);
			m_circle.setOutlineColor(m_outline_color);
			m_circle.setFillColor((m_is_active) ? m_fill_color : m_outline_color);
		}
		~RadioButton() override {}

		void setEnabled(bool enabled);
		void hide(bool hidden) override;
		void setStatus(bool flag);
		void setPosition(sf::Vector2f position) override;
		void setPositionX(float position_x);
		void setPositionY(float position_y);
		void setRadius(float radius);
		void setFillColor(sf::Color color);
		void setOnPressedCallback(std::function<void()> callback) override;
		void setOnHoverCallback(std::function<void()> callback) override;
		void setOnReleasedCallback(std::function<void()> callback) override;
		sf::Vector2f getPosition() override;
		sf::Vector2f getSize() override;
		bool isActive();

	private:
		void processEvents(const sf::Event& event) override;
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
		void update(const sf::RenderWindow& window) override;
	};
}
#endif // !SFUI_RADIO_BUTTON_HPP