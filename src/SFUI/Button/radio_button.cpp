#include "../../../include/SFUI/Button/radio_button.hpp"

void sfui::RadioButton::processEvents(const sf::Event& event) {
	if (!m_is_enabled || m_is_hidden) return;
	if (const sf::Event::MouseButtonPressed* btn_pressed = event.getIf<sf::Event::MouseButtonPressed>()) {
		m_is_pressed = m_is_hovered && (btn_pressed->button == sf::Mouse::Button::Left);
		if (m_is_hovered) m_is_active = (m_is_active) ? false : true;
	}
	if (const sf::Event::MouseButtonReleased* btn_released = event.getIf<sf::Event::MouseButtonReleased>()) {
		if (m_is_pressed && btn_released->button == sf::Mouse::Button::Left) {
			m_is_pressed = false;
			if (m_on_released_callback != nullptr) m_on_released_callback();
		}
	}
}

void sfui::RadioButton::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	if (m_is_hidden) return;
	target.draw(m_circle, states);
}

void sfui::RadioButton::update(const sf::RenderWindow& window) {
	if (!m_is_enabled || m_is_hidden) return;
	sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(window));
	m_is_hovered = sfui::isMouseOver(m_circle, mousePos);
	if (m_is_hovered && m_is_pressed) {
		m_is_pressed = true;
		if (m_on_pressed_callback != nullptr) m_on_pressed_callback();
	}
	if (m_is_hovered && !m_is_pressed) {
		if (m_on_hover_callback != nullptr) m_on_hover_callback();
	}
	m_circle.setFillColor((m_is_active) ? m_fill_color : m_outline_color);
}

void sfui::RadioButton::setEnabled(bool enabled) { m_is_enabled = enabled; }
void sfui::RadioButton::hide(bool hidden) { m_is_hidden = hidden; }
void sfui::RadioButton::setStatus(bool flag) { m_is_active = flag; }
void sfui::RadioButton::setPosition(sf::Vector2f position) { m_circle.setPosition(position); }
void sfui::RadioButton::setPositionX(float position_x) { m_circle.setPosition({ position_x, m_circle.getPosition().y }); }
void sfui::RadioButton::setPositionY(float position_y) { m_circle.setPosition({ m_circle.getPosition().x, position_y }); }
void sfui::RadioButton::setRadius(float radius) { m_circle.setRadius(radius); }
void sfui::RadioButton::setFillColor(sf::Color color) { m_fill_color = color; }
void sfui::RadioButton::setOnPressedCallback(std::function<void()> callback) { m_on_pressed_callback = callback; }
void sfui::RadioButton::setOnReleasedCallback(std::function<void()> callback) { m_on_released_callback = callback; }
void sfui::RadioButton::setOnHoverCallback(std::function<void()> callback) { m_on_hover_callback = callback; }
sf::Vector2f sfui::RadioButton::getPosition() { return m_circle.getPosition(); }
sf::Vector2f sfui::RadioButton::getSize() { return sf::Vector2f(m_circle.getRadius(), m_circle.getRadius()); }
bool sfui::RadioButton::isActive() { return m_is_active; }