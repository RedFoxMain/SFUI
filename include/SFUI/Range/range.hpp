#ifndef SFUI_RANGE_HPP
#define SFUI_RANGE_HPP

#include "../widget.hpp"
#include "../Button/button.hpp"

namespace sfui {
	class Range: public Widget {
	friend class Canvas;
	public:
		Button* slider;

	private:
		sf::Vector2f slider_base_offset_;
		sf::RectangleShape m_background;
		float m_min;
		float m_max;
		float m_value;

	public:
		Range(float max = 100, float min = 0): m_min(min), m_max(max), m_value(0) {
			m_background.setSize({ 300, 20 });
			m_background.setOutlineThickness(1);
			m_background.setOutlineColor(sf::Color::Black);

			slider = new sfui::Button();
			slider->setFillColor(sf::Color::Black);
			slider->setSize({ m_background.getSize().y, m_background.getSize().y });
			slider->setPosition(m_background.getPosition());
		}
		~Range() {
			delete slider;
		}

		/// <summary>
		/// Set max value
		/// </summary>
		/// <param name="max"></param>
		void setMaxValue(float max);

		/// <summary>
		/// Set min value
		/// </summary>
		/// <param name="min"></param>
		void setMinValue(float min);

		/// <summary>
		/// Set background color
		/// </summary>
		/// <param name="color"></param>
		void setBackgroundColor(sf::Color color);

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
		/// Set size by x
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
		void setRotation(sf::Angle degrees);

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
		/// Return the position of the Range
		/// </summary>
		/// <returns>sf::Vector2f</returns>
		sf::Vector2f getPosition() override;

		/// <summary>
		/// Return the size of the Range
		/// </summary>
		/// <returns>sf::Vector2f</returns>
		sf::Vector2f getSize();

		/// <summary>
		/// Return the angle of the Range
		/// </summary>
		/// <returns>sf::Angle</returns>
		sf::Angle getRotation();

		/// <summary>
		/// Return current value of the Range
		/// </summary>
		/// <returns>float</returns>
		float getValue();

	private:
		void draw(sf::RenderWindow* wnd) override;
		void processEvents(const sf::Event& event);
	};
}
#endif // !SFUI_RANGE_HPP