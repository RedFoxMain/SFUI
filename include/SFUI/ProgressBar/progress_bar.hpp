#ifndef SFUI_PROGRESS_BAR_HPP
#define SFUI_PROGRESS_BAR_HPP

#include "SFML/Graphics.hpp"
#include "../widget.hpp"

namespace sfui {
	class ProgressBar: public Widget {
	private:
		sf::RectangleShape m_background;
		sf::RectangleShape m_foreground;
		float m_value;
		float m_min;
		float m_max;

	public:
		ProgressBar(float max = 100, float min = 0, float value = 0): m_value(value), m_min(min), m_max(max) {
			m_background.setSize({ 300, 20 });
			m_background.setOutlineThickness(1);
			m_background.setOutlineColor(sf::Color::Black);
			m_foreground.setSize(m_background.getSize());
			m_foreground.setPosition(m_background.getPosition());
			m_foreground.setFillColor(sf::Color(128, 128, 128));
		}

		~ProgressBar() {}

		/// <summary>
		/// Update the progress bar value (progress_bar_value += value)
		/// </summary>
		/// <param name="value"></param>
		void updateValue(float value);

		/// <summary>
		/// Set the progress bar value (progress_bar_value = value)
		/// </summary>
		/// <param name="value"></param>
		void setValue(float value);

		/// <summary>
		/// Set max value for the Progress bar
		/// </summary>
		/// <param name="max"></param>
		void setMaxValue(float max);

		/// <summary>
		/// Set min value for the Progress bar
		/// </summary>
		/// <param name="min"></param>
		void setMinValue(float min);

		/// <summary>
		/// Set background color to the Pogress bar
		/// </summary>
		/// <param name="color"></param>
		void setBackColor(sf::Color color);

		/// <summary>
		/// Set foreground color to the Pogress bar
		/// </summary>
		/// <param name="color"></param>
		void setFrontColor(sf::Color color);

		/// <summary>
		/// Set position of the Progress bar by x and y
		/// </summary>
		/// <param name="position"></param>
		void setPosition(sf::Vector2f position) override;

		/// <summary>
		/// Set position of the Progress bar by x
		/// </summary>
		/// <param name="position_x"></param>
		void setPositionX(float position_x);

		/// <summary>
		/// Set position of the Progress bar by y
		/// </summary>
		/// <param name="position_y"></param>
		void setPositionY(float position_y);

		/// <summary>
		/// Set size of the Progress bar by x and y
		/// </summary>
		/// <param name="size"></param>
		void setSize(sf::Vector2f size);

		/// <summary>
		/// Set size of the Progress bar by x
		/// </summary>
		/// <param name="size_x"></param>
		void setSizeX(float size_x);

		/// <summary>
		/// Set size of the Progress bar by y
		/// </summary>
		/// <param name="size_y"></param>
		void setSizeY(float size_y);

		/// <summary>
		/// Set rotation to the Progress bar
		/// </summary>
		/// <param name="angle"></param>
		void setRotation(sf::Angle);

		/// <summary>
		/// Set border size to the Progress bar
		/// </summary>
		/// <param name="thickness"></param>
		void setOutlineThickness(float thickness);

		/// <summary>
		/// Set border color of the Progress bar
		/// </summary>
		/// <param name="color"></param>
		void setOutlineColor(sf::Color color);

		/// <summary>
		/// Return the position of the Progress bar
		/// </summary>
		/// <returns>sf::Vector2f</returns>
		sf::Vector2f getPosition() override;

		/// <summary>
		/// Return the size of the Progress bar
		/// </summary>
		/// <returns>sf::Vector2f</returns>
		sf::Vector2f getSize();

		/// <summary>
		/// Return the rotation of the Progress bar in sf::Angle
		/// </summary>
		/// <returns>sf::Angle</returns>
		sf::Angle getRotation();

		/// <summary>
		/// Return the the Progress bar value
		/// </summary>
		/// <returns></returns>
		float getValue();

	private:
		void draw(sf::RenderWindow* wnd) override;
	};
}
#endif // !SFUI_PROGRESS_BAR_HPP