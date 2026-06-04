#ifndef SFUI_RANGE_HPP
#define SFUI_RANGE_HPP

#include "../widget.hpp"
#include "../Button/button.hpp"

namespace sfui {
	class Range: public Widget, public Processable, public Updatable {
	private:
		std::unique_ptr<Button> m_slider;
		sf::Vector2f slider_base_offset_;
		sf::Vector2f slider_moved_offset_;
		sf::RectangleShape m_background;
		float m_min;
		float m_max;
		float m_value;
		bool m_is_enabled;
		bool m_is_hidden;

	public:
		Range(float max = 100, float min = 0)
			: m_min(min), m_max(max), m_value(0), m_is_enabled(true), m_is_hidden(false) {
			m_background.setSize({ 300, 20 });
			m_background.setOutlineThickness(1);
			m_background.setOutlineColor(sf::Color::Black);

			m_slider = std::unique_ptr<Button>(new sfui::Button());
			m_slider->setFillColor(sf::Color::Black);
			m_slider->setHoverColor(sf::Color::Black);
			m_slider->setPosition(m_background.getPosition());
			m_slider->setSize({ m_background.getSize().y, m_background.getSize().y });
		}
		~Range() override {}

		void setEnabled(bool enabled);
		void hide(bool hidden) override;
		void setMaxValue(float max);
		void setMinValue(float min);
		void setBackgroundColor(sf::Color color);
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
		void processEvents(const sf::Event& event) override;
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
		void update(const sf::RenderWindow& window) override;
	};
}
#endif // !SFUI_RANGE_HPP