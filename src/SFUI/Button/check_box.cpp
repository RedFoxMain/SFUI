#include "../../../include/SFUI/Button/check_box.hpp"

void sfui::CheckBox::processEvents(const sf::Event& event) {
	if (const sf::Event::MouseButtonPressed* btn_pressed = event.getIf<sf::Event::MouseButtonPressed>()) {
		m_is_pressed = m_is_hovered && (btn_pressed->button == sf::Mouse::Button::Left);
		if (m_is_hovered) m_is_active = (m_is_active) ? false : true;
	}
	if (const sf::Event::MouseButtonReleased* btn_released = event.getIf<sf::Event::MouseButtonReleased>()) {
		if (m_is_pressed && btn_released->button == sf::Mouse::Button::Left) onReleased();
	}
}

void sfui::CheckBox::draw(sf::RenderWindow* wnd) {
	sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(*wnd));
	m_is_hovered = isMouseOver(mousePos);
	if (m_is_hovered && m_is_pressed) onPressed();
	if (m_is_hovered && !m_is_pressed) onHover();
	m_rect.setFillColor((m_is_active) ? m_fill_color : m_outline_color);
	wnd->draw(m_rect);
}

void sfui::CheckBox::setStatus(bool flag) {
	m_is_active = flag;
}

void sfui::CheckBox::setPosition(sf::Vector2f position) {
	m_rect.setPosition(position);
}

void sfui::CheckBox::setPositionX(float position_x) {
	m_rect.setPosition({ position_x, m_rect.getPosition().y });
}

void sfui::CheckBox::setPositionY(float position_y) {
	m_rect.setPosition({ m_rect.getPosition().x, position_y });
}

void sfui::CheckBox::setSize(sf::Vector2f size) {
	m_rect.setSize(size);
}

void sfui::CheckBox::setSizeX(float size_x) {
	m_rect.setSize({ size_x, m_rect.getPosition().y });
}

void sfui::CheckBox::setSizeY(float size_y) {
	m_rect.setPosition({ m_rect.getPosition().x, size_y });
}

void sfui::CheckBox::setRotation(sf::Angle angle) {
	m_rect.setRotation(angle);
}

void sfui::CheckBox::setFillColor(sf::Color color) {
	m_rect.setFillColor(m_fill_color = color);
}

void sfui::CheckBox::setOnPressedCallback(std::function<void()> on_pressed_callback) {
	m_on_pressed_callback = m_on_pressed_callback;
}

void sfui::CheckBox::setOnHoverCallback(std::function<void()> on_hover_callback) {
	m_on_hover_callback = on_hover_callback;
}

void sfui::CheckBox::setOnReleasedCallback(std::function<void()> on_released_callback) {
	m_on_released_callback = m_on_released_callback;
}

sf::Vector2f sfui::CheckBox::getPosition() {
	return m_rect.getPosition();
}

sf::Vector2f sfui::CheckBox::getSize() {
	return m_rect.getSize();
}

sf::Angle sfui::CheckBox::getRotation() {
	return m_rect.getRotation();
}

bool sfui::CheckBox::isActive() {
	return m_is_active;
}

void sfui::CheckBox::onHover() {
	if (m_on_hover_callback) m_on_hover_callback();
}

void sfui::CheckBox::onPressed() {
	m_is_pressed = true;
	if (m_on_pressed_callback) m_on_pressed_callback();
}

void sfui::CheckBox::onReleased() {
	m_is_pressed = false;
	if (m_on_released_callback) m_on_released_callback();
}

bool sfui::CheckBox::isMouseOver(sf::Vector2f mouse_pos) {
	return m_rect.getGlobalBounds().contains(mouse_pos);;
}