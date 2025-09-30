#ifndef SFUI_TEXT_HPP
#define SFUI_TEXT_HPP

#include "../widget.hpp"

namespace sfui {
	class Text: public Widget {
	friend class Canvas;
	friend class Window;
	friend class Button;
	friend class TextBox;
	private:
		sf::Text* m_text;

	public:
		Text(sf::Font& font, const std::string& text = "", unsigned int size = 32) {
			m_text = new sf::Text(font, text, size);
		}
		~Text() {
			delete m_text;
		}
		void setOrigin(sf::Vector2f origin);
		void setPosition(sf::Vector2f position) override;
		void setPositionX(float position_x);
		void setPositionY(float position_y);
		void setRotation(sf::Angle angle);
		void setFont(const sf::Font& font);
		void setString(const sf::String& string);
		void setCharacterSize(unsigned int size);
		void setLineSpacing(float spacing_factor);
		void setLetterSpacing(float spacing_factor);
		void setStyle(uint32_t style);
		void setFillColor(sf::Color color);
		void setOutlineColor(sf::Color color);
		void setOutlineThickness(float thickness);

		sf::Vector2f getPosition() override;
		sf::Angle getRotation();
		sf::String getString();
		sf::Vector2f getOrigin();
		sf::Font getFont();
		unsigned int getCharacterSize();
		float getLetterSpacing();
		float getLineSpacing();
		uint32_t getStyle();
		sf::Color getFillColor();
		sf::Color getOutlineColor();
		float getOutlineThickness();
		sf::Vector2f findCharacterPos(std::size_t index);
		sf::FloatRect getLocalBounds();
		sf::FloatRect getGlobalBounds();

	private:
		void draw(sf::RenderWindow* wnd) override;
	};
}
#endif // !SFUI_TEXT_HPP