#include "../../../include/SFUI/Button/radio_button.hpp"

void sfui::RadioButton::processEvents(const sf::Event& event) {
	if (const sf::Event::MouseButtonPressed* btn_pressed = event.getIf<sf::Event::MouseButtonPressed>()) {
		m_is_pressed = m_is_hovered && (btn_pressed->button == sf::Mouse::Button::Left);
		if(m_is_hovered) m_is_active = (m_is_active) ? false : true;
	}
	if (const sf::Event::MouseButtonReleased* btn_released = event.getIf<sf::Event::MouseButtonReleased>()) {
		if (m_is_pressed && btn_released->button == sf::Mouse::Button::Left) onReleased();
	}
}

void sfui::RadioButton::draw(sf::RenderWindow* wnd) {
	sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(*wnd));
	m_is_hovered = isMouseOver(mousePos);
	if (m_is_hovered && m_is_pressed) onPressed();
	if (m_is_hovered && !m_is_pressed) onHover();
	m_circle.setFillColor((m_is_active) ? m_fill_color : m_outline_color);
	wnd->draw(m_circle);
}

void sfui::RadioButton::setStatus(bool flag) {
	m_is_active = flag;
}

void sfui::RadioButton::setPosition(sf::Vector2f position) {
	m_circle.setPosition(position);
}

void sfui::RadioButton::setPositionX(float position_x) {
	m_circle.setPosition({ position_x, m_circle.getPosition().y });
}

void sfui::RadioButton::setPositionY(float position_y) {
	m_circle.setPosition({ m_circle.getPosition().x, position_y });
}

void sfui::RadioButton::setRadius(float size) {
	m_circle.setRadius(size);
}

void sfui::RadioButton::setFillColor(sf::Color color) {
	m_circle.setFillColor(m_fill_color = color);
}

void sfui::RadioButton::setOnPressedCallback(std::function<void()> on_pressed_callback) {
	m_on_pressed_callback = m_on_pressed_callback;
}

void sfui::RadioButton::setOnHoverCallback(std::function<void()> on_hover_callback) {
	m_on_hover_callback = on_hover_callback;
}

void sfui::RadioButton::setOnReleasedCallback(std::function<void()> on_released_callback) {
	m_on_released_callback = m_on_released_callback;
}

sf::Vector2f sfui::RadioButton::getPosition() {
	return m_circle.getPosition();
}

float sfui::RadioButton::getSize() {
	return m_circle.getRadius();
}

bool sfui::RadioButton::isActive() {
	return m_is_active;
}

void sfui::RadioButton::onHover() {
	if (m_on_hover_callback) m_on_hover_callback();
}

void sfui::RadioButton::onPressed() {
	m_is_pressed = true;
	if (m_on_pressed_callback) m_on_pressed_callback();
}

void sfui::RadioButton::onReleased() {
	m_is_pressed = false;
	if (m_on_released_callback) m_on_released_callback();
}

bool sfui::RadioButton::isMouseOver(sf::Vector2f mouse_pos) {
	return m_circle.getGlobalBounds().contains(mouse_pos);;
}