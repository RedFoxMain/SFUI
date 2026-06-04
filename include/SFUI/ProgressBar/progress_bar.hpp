#ifndef SFUI_PROGRESS_BAR_HPP
#define SFUI_PROGRESS_BAR_HPP

#include "../widget.hpp"

namespace sfui {
	class ProgressBar: public Widget, public Updatable {
	private:
		sf::RectangleShape m_background;
		sf::RectangleShape m_foreground;
		float m_value;
		float m_min;
		float m_max;
		bool m_is_enabled;
		bool m_is_hidden;

	public:
		ProgressBar(float max = 100, float min = 0, float value = 0)
			: m_is_enabled(true), m_is_hidden(false), m_value(value), m_min(min), m_max(max) {
			m_background.setSize({ 300, 20 });
			m_background.setOutlineThickness(1);
			m_background.setOutlineColor(sf::Color::Black);
			m_foreground.setSize(m_background.getSize());
			m_foreground.setPosition(m_background.getPosition());
			m_foreground.setFillColor(sf::Color(128, 128, 128));
		}
		~ProgressBar() override {}

		void setEnabled(bool enabled);
		void hide(bool hidden) override;
		void updateValue(float value);
		void setValue(float value);
		void setMaxValue(float max);
		void setMinValue(float min);
		void setBackColor(sf::Color color);
		void setFrontColor(sf::Color color);
		void setPosition(sf::Vector2f position) override;
		void setPositionX(float position_x);
		void setPositionY(float position_y);
		void setSize(sf::Vector2f size);
		void setSizeX(float size_x);
		void setSizeY(float size_y);
		void setOutlineThickness(float thickness);
		void setOutlineColor(sf::Color color);
		sf::Vector2f getPosition() override;
		sf::Vector2f getSize() override;
		float getValue();

	private:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
		void update(const sf::RenderWindow& window) override;
	};
}
#endif // !SFUI_PROGRESS_BAR_HPP