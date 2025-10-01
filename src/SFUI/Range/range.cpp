#include "../../../include/SFUI/Range/range.hpp"

void sfui::Range::processEvents(const sf::Event& event) {
	slider->processEvents(event);
	if (const auto* mouse_pressed = event.getIf<sf::Event::MouseButtonPressed>()) {
		if (slider->isPressed()) slider_moved_offset_.x = mouse_pressed->position.x - slider->getPosition().x;
	}
	if (const auto* mouse_pos = event.getIf<sf::Event::MouseMoved>()) {
		if (slider->isPressed()) {
			float mouse_x = mouse_pos->position.x - slider_moved_offset_.x;
			float min_x = m_background.getPosition().x;
			float max_x = m_background.getPosition().x + m_background.getSize().x - slider->getSize().x;
			float new_x = std::clamp(mouse_x, min_x, max_x);
			slider->setPosition({ new_x, slider->getPosition().y });
			slider_base_offset_.x = slider->getPosition().x - m_background.getPosition().x;
			float ratio = (new_x - m_background.getPosition().x) / (m_background.getSize().x - slider->getSize().x);
			m_value = m_min + ratio * (m_max - m_min);
		}
	}
}

void sfui::Range::draw(sf::RenderWindow* wnd) {
	wnd->draw(m_background);
	slider->draw(wnd);
}

void sfui::Range::setMaxValue(float max) {
	m_max = max;
}

void sfui::Range::setMinValue(float min) {
	m_min = min;
}

void sfui::Range::setBackgroundColor(sf::Color color) {
	m_background.setFillColor(color);
}

void sfui::Range::setPosition(sf::Vector2f position) {
	m_background.setPosition(position);
	slider->setPosition(m_background.getPosition() + slider_base_offset_);
}

void sfui::Range::setPositionX(float position_x) {
	m_background.setPosition({ position_x, m_background.getPosition().y });
	slider->setPosition(m_background.getPosition() + slider_base_offset_);
}

void sfui::Range::setPositionY(float position_y) {
	m_background.setPosition({ m_background.getPosition().x, position_y });
	slider->setPosition(m_background.getPosition() + slider_base_offset_);
}

void sfui::Range::setSize(sf::Vector2f size) {
	m_background.setSize(size);
	slider->setSize({ size.y, size.y });
}

void sfui::Range::setSizeX(float size_x) {
	m_background.setSize({ size_x, m_background.getSize().y });
	slider->setSize(m_background.getSize());
}

void sfui::Range::setSizeY(float size_y) {
	m_background.setSize({ m_background.getSize().x, size_y });
	slider->setSize({ m_background.getSize().y, m_background.getSize().y });
}

void sfui::Range::setRotation(sf::Angle degrees) {
	m_background.setRotation(degrees);
	slider->setRotation(degrees);
}

void sfui::Range::setOutlineThickness(float thickness) {
	m_background.setOutlineThickness(thickness);
}

void sfui::Range::setOutlineColor(sf::Color color) {
	m_background.setOutlineColor(color);
}

sf::Vector2f sfui::Range::getPosition() {
	return m_background.getPosition();
}

sf::Vector2f sfui::Range::getSize() {
	return m_background.getSize();
}

sf::Angle sfui::Range::getRotation() {
	return m_background.getRotation();
}

float sfui::Range::getValue() {
	return m_value;
}