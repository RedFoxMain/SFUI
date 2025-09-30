#ifndef SFUI_TEXT_BOX_HPP
#define SFUI_TEXT_BOX_HPP

#include "SFML/Graphics.hpp"
#include "../widget.hpp"
#include "../Text/text.hpp"

#define BAKSPACE_KEY 8

namespace sfui {
	class TextBox: public Widget {
	friend class Canvas;
	public:
		Text* place_holder;
		Text* text;

	private:
		sf::RectangleShape m_rect;
		sf::Font m_font;
		std::string input_string_;
		bool draw_place_holder_;
		bool is_active_ = false;

	public:
		TextBox(Text* place_holder): 
			place_holder(place_holder), draw_place_holder_(true) {
			place_holder->setFillColor(sf::Color(128, 128, 128));
			place_holder->setPosition(m_rect.getPosition());

			m_font = place_holder->getFont();

			text = new Text(m_font);
			text->setFillColor(sf::Color::Black);
			text->setPosition(place_holder->getPosition());
			text->setCharacterSize(place_holder->getCharacterSize());

			m_rect.setSize(sf::Vector2f(300, place_holder->getCharacterSize()));
			m_rect.setFillColor(sf::Color::White);
			m_rect.setOutlineThickness(1);
			m_rect.setOutlineColor(sf::Color::Black);
			centrateText();
		}

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
		/// Return the rotation
		/// </summary>
		/// <returns>sf::Angle</returns>
		sf::Angle getRotation(); 
		
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