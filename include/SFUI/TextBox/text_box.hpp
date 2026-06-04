 #ifndef SFUI_TEXT_BOX_HPP
#define SFUI_TEXT_BOX_HPP

#include "../widget.hpp"
#include "../Label/label.hpp"

#define BAKSPACE_KEY 0x8

namespace sfui {
	class TextBox: public Widget, public Processable, public Updatable {
	private:
		std::unique_ptr<Label> m_text;
		std::unique_ptr<Label> m_place_holder;
		sf::RectangleShape m_rect;
		sf::Font m_font;
		std::string m_input_string;
		bool m_draw_place_holder;
		bool m_is_active;
		bool m_is_enabled;
		bool m_is_hidden;
		float m_glyph_size;

	public:
		TextBox(const std::string& place_holder = "")
			: m_draw_place_holder(true), m_is_active(false), m_is_enabled(true), m_is_hidden(false), m_place_holder(nullptr) {
			m_text = std::unique_ptr<Label>(new Label());
			m_text->setFillColor(sf::Color::Black);
			m_text->setCharacterSize(14);
			m_glyph_size = m_font.getGlyph('A', m_text->getCharacterSize(), false).advance;
			m_font = m_text->getFont();
			
			m_rect.setSize(sf::Vector2f(300.f, static_cast<float>(m_text->getCharacterSize() * 2)));
			m_rect.setFillColor(sf::Color::White);
			m_rect.setOutlineThickness(1);
			m_rect.setOutlineColor(sf::Color::Black);
			
			if (!place_holder.empty()) {
				m_place_holder = std::unique_ptr<Label>(new Label(place_holder));
				m_place_holder->setFillColor(sf::Color(128, 128, 128));
				m_place_holder->setCharacterSize(m_text->getCharacterSize());
			}
			centrateText();
		}

		~TextBox() override {}

		void setEnabled(bool enabled);
		void hide(bool hidden) override;
		void setTextColor(sf::Color color);
		void setPlaceHolderText(const std::string& text);
		void setText(const std::string& text);
		void setTextSize(float size);
		void setPosition(sf::Vector2f position) override;
		void setPositionX(float position_x);
		void setPositionY(float position_y);
		void setSize(sf::Vector2f size);
		void setSizeX(float size_x);
		void setSizeY(float size_y);
		void setBackgroundColor(sf::Color color);
		void setOutlineThickness(float thickness);
		void setOutlineColor(sf::Color color);
		sf::Vector2f getPosition() override;
		sf::Vector2f getSize() override;
		std::string getText();

	private:
		void update(const sf::RenderWindow& window);
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
		void processEvents(const sf::Event& event) override;

	private:
		void centrateText();
	};
}
#endif // !SFUI_TEXT_BOX_HPP