#include "../../../include/SFUI/Button/button.hpp"

void sfui::Button::processEvents(const sf::Event& event) {
	if (const sf::Event::MouseButtonPressed* btn_pressed = event.getIf<sf::Event::MouseButtonPressed>()) {
		if (m_is_hovered && (btn_pressed->button == sf::Mouse::Button::Left)) {
			onPressed();
			m_is_pressed = true;
			m_hold_timer.restart();
		}
	}
	if (const sf::Event::MouseButtonReleased* btn_released = event.getIf<sf::Event::MouseButtonReleased>()) {
		if (m_is_pressed && btn_released->button == sf::Mouse::Button::Left) { 
			onReleased(); 
			m_is_pressed = false;
			m_is_hold = false;
			m_hold_timer.restart();
		}
	}
	
}

void sfui::Button::draw(sf::RenderWindow* wnd) {
	sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(*wnd));
	m_is_hovered = isMouseOver(mousePos);
	// onHover event handler
	if (m_is_hovered && !m_is_pressed) onHover();
	else m_rect.setFillColor(m_fill_color);
	// onHold event handler
	if (m_is_pressed && m_hold_timer.getElapsedTime() >= m_hold_delay) onHold();
	wnd->draw(m_rect);
	if (text != nullptr) {
		centrateText();
		text->draw(wnd);
	}
}

void sfui::Button::centrateText() {
	text->setOrigin({
		text->getLocalBounds().position.x + text->getGlobalBounds().size.x / 2.f,
		text->getLocalBounds().position.y + text->getGlobalBounds().size.y / 2.f
	});
	text->setPosition({
		m_rect.getGlobalBounds().position.x + m_rect.getGlobalBounds().size.x / 2.f,
		m_rect.getGlobalBounds().position.y + m_rect.getGlobalBounds().size.y / 2.f
	});
}

bool sfui::Button::isMouseOver(sf::Vector2f mouse_pos) {
	return m_rect.getGlobalBounds().contains(mouse_pos);
}

void sfui::Button::setPosition(sf::Vector2f position) {
	m_rect.setPosition(position);
}

void sfui::Button::setPositionX(float position_x) {
	m_rect.setPosition({ position_x, m_rect.getPosition().y });
}

void sfui::Button::setPositionY(float position_y) {
	m_rect.setPosition({ m_rect.getPosition().x, position_y });
}

void sfui::Button::setSize(sf::Vector2f size) {
	m_rect.setSize(size);
}

void sfui::Button::setSizeX(float size_x) {
	m_rect.setSize({ size_x, m_rect.getSize().y });
}

void sfui::Button::setSizeY(float size_y) {
	m_rect.setSize({ m_rect.getSize().x, size_y });
}

void sfui::Button::setRotation(sf::Angle angle) {
	m_rect.setRotation(angle);
	if(text) text->setRotation(angle);
}

void sfui::Button::setFillColor(sf::Color color) {
	m_fill_color = color;
}

void sfui::Button::setHoverColor(sf::Color color) {
	m_hover_color = color;
}

void sfui::Button::setTexture(const std::string& texture_path) {
	m_texture = new sf::Texture(texture_path);
	m_rect.setTexture(m_texture);
}
 
void sfui::Button::setOutlineThickness(float thickness) {
	m_rect.setOutlineThickness(thickness);
}

void sfui::Button::setOutlineColor(sf::Color color) {
	m_rect.setOutlineColor(color);
}

void sfui::Button::setOnPressedCallback(std::function<void()> on_pressed_callback) {
	m_on_pressed_callback = on_pressed_callback;
}

void sfui::Button::setOnHoverCallback(std::function<void()> on_hover_callback) {
	m_on_hover_callback = on_hover_callback;
}

void sfui::Button::setOnReleasedCallback(std::function<void()> on_released_callback) {
	m_on_released_callback = on_released_callback;
}

sf::Vector2f sfui::Button::getPosition() {
	return m_rect.getPosition();
}

sf::Vector2f sfui::Button::getSize() {
	return m_rect.getSize();
}

sf::Angle sfui::Button::getRotation() {
	return m_rect.getRotation();
}

bool sfui::Button::isPressed() {
	return m_is_pressed;
}

bool sfui::Button::isHovered() {
	return m_is_hovered;
}

void sfui::Button::onHover() {
	m_rect.setFillColor(m_hover_color);
	if (m_on_hover_callback) m_on_hover_callback();
}

void sfui::Button::onPressed() {
	m_rect.setFillColor(m_fill_color);
	if(m_on_pressed_callback) m_on_pressed_callback();
}

void sfui::Button::onReleased() {
	m_rect.setFillColor(m_hover_color);
	if (m_on_released_callback) m_on_released_callback();
}

void sfui::Button::onHold() {
	onPressed();
	m_hold_timer.restart();
}