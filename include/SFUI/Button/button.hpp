#ifndef SFUI_BUTTON_HPP
#define SFUI_BUTTON_HPP

#include "../widget.hpp"
#include "../Label/label.hpp"
#include "button_interface.hpp"

namespace sfui {
	class Button: public Widget, public Processable, public Updatable, ButtonBase {
	private:
		std::unique_ptr<Label> m_text;
		sf::RectangleShape m_rect;
		sf::Color m_fill_color;
		sf::Color m_hover_color;
		bool m_is_hovered;
		bool m_is_pressed;
		bool m_is_hold;
		bool m_is_enabled;
		bool m_is_hidden;
		std::function<void()> m_on_pressed_callback = nullptr;
		std::function<void()> m_on_released_callback = nullptr;
		std::function<void()> m_on_hover_callback = nullptr;
		sf::Clock m_hold_timer;
		sf::Time m_hold_delay;

	public:
		Button(const std::string& text = "", std::function<void()> callback = nullptr)
			: m_on_pressed_callback(callback), m_on_hover_callback(nullptr), m_on_released_callback(nullptr),
			m_is_pressed(false), m_is_hovered(false), m_is_hold(false), m_is_enabled(true), m_is_hidden(false),
			m_fill_color(sf::Color(125, 125, 125)), m_hover_color(sf::Color::Green) {
			m_hold_delay = sf::seconds(0.15f);
			m_rect.setSize({ 80.f, 30.f });
			m_rect.setFillColor(m_fill_color);
			m_rect.setOutlineThickness(1);
			m_rect.setOutlineColor(sf::Color::Black);
			if (!text.empty()) {
				m_text = std::unique_ptr<Label>(new Label(text, 14));
				m_text->setFillColor(sf::Color::Black);
			}
		}

		~Button() override {}

		void setEnabled(bool enabled);
		void hide(bool hidden) override;
		void setPosition(sf::Vector2f position) override;
		void setPositionX(float position_x);
		void setPositionY(float position_y);
		void setSize(sf::Vector2f size);
		void setSizeX(float size_x);
		void setSizeY(float size_y);
		void setFillColor(sf::Color color);
		void setHoverColor(sf::Color color);
		void setOutlineThickness(float thickness);
		void setOutlineColor(sf::Color color);

		void setTextFont(const sf::Font& font);
		void setTextFont(const std::string& path);
		void setText(const sf::String& string);
		void setTextCharacterSize(unsigned int size);
		void setTextLineSpacing(float spacing_factor);
		void setTextLetterSpacing(float spacing_factor);
		void setTextStyle(uint32_t style);
		void setTextFillColor(sf::Color color);
		void setTextOutlineColor(sf::Color color);
		void setTextOutlineThickness(float thickness);

		sf::Vector2f getPosition() override;
		sf::Vector2f getSize() override;
		sf::String getText();
		bool isPressed();

		void setOnPressedCallback(std::function<void()> callback) override;
		void setOnReleasedCallback(std::function<void()> callback) override;
		void setOnHoverCallback(std::function<void()> callback) override;

	private:
		void processEvents(const sf::Event& event) override;
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
		void update(const sf::RenderWindow& window) override;

		void centrateText();

		void onHover();
		void onPressed();
		void onReleased();
	};
}
#endif // !SFUI_BUTTON_HPP