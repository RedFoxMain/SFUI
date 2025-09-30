#include "../../../include/SFUI/ProgressBar/progress_bar.hpp"

void sfui::ProgressBar::draw(sf::RenderWindow* wnd) {
	float clampedValue = std::clamp(m_value, m_min, m_max);
	m_foreground.setSize({ clampedValue * m_background.getSize().x / m_max, m_foreground.getSize().y });
	wnd->draw(m_background);
	wnd->draw(m_foreground);
}

void sfui::ProgressBar::updateValue(float value) {
	m_value += value;
}

void sfui::ProgressBar::setValue(float value) {
	m_value = value;
}

void sfui::ProgressBar::setMaxValue(float max) {
	m_max = max;
}

void sfui::ProgressBar::setMinValue(float min) {
	m_min = min;
}

void sfui::ProgressBar::setBackColor(sf::Color color) {
	m_background.setFillColor(color);
}

void sfui::ProgressBar::setFrontColor(sf::Color color) {
	m_foreground.setFillColor(color);
}

void sfui::ProgressBar::setPosition(sf::Vector2f position) {
	m_foreground.setPosition(position);
	m_background.setPosition(position);
}

void sfui::ProgressBar::setPositionX(float position_x) {
	m_foreground.setPosition({ position_x, m_foreground.getPosition().y });
	m_background.setPosition(m_foreground.getPosition());
}

void sfui::ProgressBar::setPositionY(float position_y) {
	m_foreground.setPosition({ m_foreground.getPosition().x, position_y });
	m_background.setPosition(m_foreground.getPosition());
}

void sfui::ProgressBar::setSize(sf::Vector2f size) {
	m_foreground.setSize(size);
	m_background.setSize(size);
}

void sfui::ProgressBar::setSizeX(float size_x) {
	m_foreground.setSize({ size_x, m_foreground.getSize().y });
	m_background.setSize(m_foreground.getSize());
}

void sfui::ProgressBar::setSizeY(float size_y) {
	m_foreground.setSize({ m_foreground.getSize().x, size_y });
	m_background.setSize(m_foreground.getSize());
}

void sfui::ProgressBar::setRotation(sf::Angle angle) {
	m_foreground.setRotation(angle);
	m_background.setRotation(angle);
}

void sfui::ProgressBar::setOutlineThickness(float thickness) {
	m_background.setOutlineThickness(thickness);
}

void sfui::ProgressBar::setOutlineColor(sf::Color color) {
	m_background.setOutlineColor(color);
}

sf::Vector2f sfui::ProgressBar::getPosition() {
	return m_background.getPosition();
}

sf::Vector2f sfui::ProgressBar::getSize() {
	return m_background.getSize();
}

sf::Angle sfui::ProgressBar::getRotation() {
	return m_background.getRotation();
}

float sfui::ProgressBar::getValue() {
	return m_value;
}