#include "../../../include/SFUI/Range/range.hpp"

void sfui::Range::processEvents(const sf::Event& event) {
	if (!m_is_enabled || m_is_hidden) return;
	if (Processable* slider_ptr = dynamic_cast<Processable*>(m_slider.get()))
		slider_ptr->processEvents(event);
	if (const auto* mouse_pos = event.getIf<sf::Event::MouseMoved>()) {
		if (m_slider->isPressed()) {
			float mouse_x = mouse_pos->position.x - slider_moved_offset_.x;
			float min_x = m_background.getPosition().x;
			float max_x = m_background.getPosition().x + m_background.getSize().x - m_slider->getSize().x;
			float new_x = std::clamp(mouse_x, min_x, max_x);
			m_slider->setPosition({ new_x, m_slider->getPosition().y });
			slider_base_offset_.x = m_slider->getPosition().x - m_background.getPosition().x;
			float ratio = (new_x - m_background.getPosition().x) / (m_background.getSize().x - m_slider->getSize().x);
			m_value = m_min + ratio * (m_max - m_min);
		}
	}
}

void sfui::Range::update(const sf::RenderWindow& window) {
	if (!m_is_enabled || m_is_hidden) return;
	if (Updatable* slider_ptr = dynamic_cast<Updatable*>(m_slider.get()))
		slider_ptr->update(window);
}

void sfui::Range::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	if (m_is_hidden) return;
	target.draw(m_background, states);
	target.draw(*m_slider, states);
}
void sfui::Range::setEnabled(bool enabled) { m_is_enabled = enabled; }
void sfui::Range::hide(bool hidden) { m_is_hidden = hidden; }
void sfui::Range::setMaxValue(float max) { m_max = max; }
void sfui::Range::setMinValue(float min) { m_min = min; }
void sfui::Range::setBackgroundColor(sf::Color color) { m_background.setFillColor(color); }
void sfui::Range::setOutlineThickness(float thickness) { m_background.setOutlineThickness(thickness); }
void sfui::Range::setOutlineColor(sf::Color color) { m_background.setOutlineColor(color); }

void sfui::Range::setPosition(sf::Vector2f position) {
	m_background.setPosition(position);
	m_slider->setPosition(m_background.getPosition() + slider_base_offset_);
}

void sfui::Range::setPositionX(float position_x) {
	m_background.setPosition({ position_x, m_background.getPosition().y });
	m_slider->setPosition(m_background.getPosition() + slider_base_offset_);
}

void sfui::Range::setPositionY(float position_y) {
	m_background.setPosition({ m_background.getPosition().x, position_y });
	m_slider->setPosition(m_background.getPosition() + slider_base_offset_);
}

void sfui::Range::setSize(sf::Vector2f size) {
	m_background.setSize(size);
	m_slider->setSize({ size.y, size.y });
}

void sfui::Range::setSizeX(float size_x) {
	m_background.setSize({ size_x, m_background.getSize().y });
	m_slider->setSize(m_background.getSize());
}

void sfui::Range::setSizeY(float size_y) {
	m_background.setSize({ m_background.getSize().x, size_y });
	m_slider->setSize({ m_background.getSize().y, m_background.getSize().y });
}

sf::Vector2f sfui::Range::getPosition() { return m_background.getPosition(); }
sf::Vector2f sfui::Range::getSize() { return m_background.getSize(); }
float sfui::Range::getValue() { return m_value; }