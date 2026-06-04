#ifndef SFUI_LABEL_HPP
#define SFUI_LABEL_HPP

#include <filesystem>
#include "../widget.hpp"
#include "../config.h"

namespace sfui {
	class Label: public Widget {
	private:
		sf::Font m_font;
		std::unique_ptr<sf::Text> m_text;
		bool m_is_hidden;

	public:
		Label(const std::string& text = "", unsigned int size = 32)
			: m_text(new sf::Text(m_font, text, size)), m_is_hidden(false) {
			if (!m_font.openFromFile(DEFAULT_FONT)) throw std::runtime_error("Can't load default font!");
			m_text->setFillColor(sf::Color::Black);
		}

		~Label() override {}

		void setPosition(sf::Vector2f position) override;
		sf::Vector2f getPosition() override;
		sf::Vector2f getSize() override;

		void setEnabled(bool enabled);
		void hide(bool hidden) override;
		void setPositionX(float position_x);
		void setPositionY(float position_y);
		void setFont(const sf::Font& font);
		void setFont(const std::string& path);
		void setText(const sf::String& text);
		void setCharacterSize(unsigned int size);
		void setLineSpacing(float spacing_factor);
		void setLetterSpacing(float spacing_factor);
		void setStyle(uint32_t style);
		void setFillColor(sf::Color color);
		void setOutlineColor(sf::Color color);
		void setOutlineThickness(float thickness);

		sf::String getText();
		sf::Font getFont();
		unsigned int getCharacterSize();
		float getLetterSpacing();
		float getLineSpacing();
		uint32_t getStyle();
		sf::Color getFillColor();
		sf::Color getOutlineColor();
		float getOutlineThickness();
		sf::Vector2f findCharacterPos(std::size_t index);

	private:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	};
}
#endif // !SFUI_LABEL_HPP