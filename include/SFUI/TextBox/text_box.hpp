#ifndef SFUI_TEXT_BOX_HPP
#define SFUI_TEXT_BOX_HPP

#include "SFML/Graphics.hpp"
#include "../widget.hpp"
#include "../Text/text.hpp"
#define BAKSPACE_KEY 0x8

namespace sfui {
	class TextBox: public virtual Widget {
	friend class Layout;
	private:
		Text* m_place_holder;
		Text* m_text;
		sf::RectangleShape m_rect;
		sf::Font m_font;
		std::string input_string_;
		bool draw_place_holder_;
		bool is_active_;
		bool m_is_enabled;
		float glyph_size_;

	public:
		TextBox(Text* place_holder): 
			m_place_holder(place_holder), draw_place_holder_(true), is_active_(false), m_is_enabled(true) {
			m_place_holder->setFillColor(sf::Color(128, 128, 128));
			m_place_holder->setPosition(m_rect.getPosition());
			m_font = m_place_holder->getFont();
			glyph_size_ = m_font.getGlyph('A', m_place_holder->getCharacterSize(), false).advance;

			m_text = new Text(m_font);
			m_text->setFillColor(sf::Color::Black);
			m_text->setPosition(m_place_holder->getPosition());
			m_text->setCharacterSize(m_place_holder->getCharacterSize());

			m_rect.setSize(sf::Vector2f(300.f, static_cast<float>(m_place_holder->getCharacterSize())));
			m_rect.setFillColor(sf::Color::White);
			m_rect.setOutlineThickness(1);
			m_rect.setOutlineColor(sf::Color::Black);
			centrateText();
		}

		/// <summary>
		/// Set widget enabled or disabled
		/// </summary>
		/// <param name="flag"></param>
		void setEnabled(bool flag);

		/// <summary>
		/// Set the color for text
		/// </summary>
		/// <param name="color"></param>
		void setTextColor(sf::Color color);

		/// <summary>
		/// Set placeholder text
		/// </summary>
		/// <param name="text"></param>
		void setPlaceHolderText(const std::string& text);

		/// <summary>
		/// Set text to the TextBox
		/// </summary>
		/// <param name="text"></param>
		void setText(const std::string& text);

		/// <summary>
		/// Set the position by x and y
		/// </summary>
		/// <param name="position"></param>
		void setPosition(sf::Vector2f position) override;

		/// <summary>
		/// Set the position by x
		/// </summary>
		/// <param name="position_x"></param>
		void setPositionX(float position_x);

		/// <summary>
		/// Set the position by y
		/// </summary>
		/// <param name="position_y"></param>
		void setPositionY(float position_y);

		/// <summary>
		/// Set the size by x and y
		/// </summary>
		/// <param name="size"></param>
		void setSize(sf::Vector2f size);

		/// <summary>
		/// Set the position by x
		/// </summary>
		/// <param name="size_x"></param>
		void setSizeX(float size_x);

		/// <summary>
		/// Set the position by y
		/// </summary>
		/// <param name="size_y"></param>
		void setSizeY(float size_y);

		/// <summary>
		/// Set the background color
		/// </summary>
		/// <param name="color"></param>
		void setBackgroundColor(sf::Color color);

		/// <summary>
		/// Set border size
		/// </summary>
		/// <param name="thickness"></param>
		void setOutlineThickness(float thickness);

		/// <summary>
		/// Set border color
		/// </summary>
		/// <param name="color"></param>
		void setOutlineColor(sf::Color color);

		/// <summary>
		/// Return the position
		/// </summary>
		/// <returns>sf::Vector2f</returns>
		sf::Vector2f getPosition() override;

		/// <summary>
		/// Return the size
		/// </summary>
		/// <returns>sf::Vector2f</returns>
		sf::Vector2f getSize();

		/// <summary>
		/// Get entered text
		/// </summary>
		/// <returns></returns>
		std::string getText();
		
	private:
		void draw(sf::RenderWindow* wnd) override;
		void processEvents(const sf::Event& event);

	private:
		void centrateText();
		void updateSize();
		bool isMouseOver(sf::Vector2f mouse_position);
	};
}
#endif // !SFUI_TEXT_BOX_HPP