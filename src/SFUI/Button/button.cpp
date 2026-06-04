#include "../../../include/SFUI/Button/button.hpp"

void sfui::Button::processEvents(const sf::Event& event) {
	if (!m_is_enabled || m_is_hidden) return;
	if (const sf::Event::MouseButtonPressed* btn_pressed = event.getIf<sf::Event::MouseButtonPressed>()) {
		if (m_is_hovered && btn_pressed->button == sf::Mouse::Button::Left) {
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

void sfui::Button::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	if (m_is_hidden) return;
	target.draw(m_rect, states);
	if (m_text != nullptr)
		target.draw(*m_text, states);
}

void sfui::Button::update(const sf::RenderWindow& window) {
	if (!m_is_enabled || m_is_hidden) return;
	sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(window));
	m_is_hovered = sfui::isMouseOver(m_rect, mousePos);
	if (m_is_hovered && !m_is_pressed) onHover();
	else m_rect.setFillColor(m_fill_color);
	if (m_is_pressed && m_hold_timer.getElapsedTime() >= m_hold_delay) {
		m_rect.setFillColor(m_fill_color);
		if (m_on_pressed_callback != nullptr) m_on_pressed_callback();
		m_is_hold = true;
		m_hold_timer.restart();
	}
	if (m_text != nullptr) {
		if (m_text->getSize().x > this->getSize().x)
			this->setSizeX(this->getSize().x + m_text->getSize().x / 2.f + m_text->getCharacterSize());
		else if (m_text->getSize().y > this->getSize().y)
			this->setSizeY(this->getSize().y + m_text->getSize().y / 2.f + m_text->getCharacterSize());
		this->centrateText();
	}
}

void sfui::Button::setEnabled(bool flag) { m_is_enabled = flag; }
void sfui::Button::hide(bool hidden) { m_is_hidden = hidden; }
void sfui::Button::setPosition(sf::Vector2f position) { m_rect.setPosition(position); }
void sfui::Button::setPositionX(float position_x) { m_rect.setPosition({ position_x, m_rect.getPosition().y }); }
void sfui::Button::setPositionY(float position_y) { m_rect.setPosition({ m_rect.getPosition().x, position_y}); }
void sfui::Button::setSize(sf::Vector2f size) { m_rect.setSize(size); }
void sfui::Button::setSizeX(float size_x) { m_rect.setSize({ size_x, m_rect.getSize().y }); }
void sfui::Button::setSizeY(float size_y) { m_rect.setSize({ m_rect.getSize().x, size_y }); }
void sfui::Button::setFillColor(sf::Color color) { m_fill_color = color; }
void sfui::Button::setHoverColor(sf::Color color) { m_hover_color = color; }
void sfui::Button::setOutlineThickness(float thickness) { m_rect.setOutlineThickness(thickness); }
void sfui::Button::setOutlineColor(sf::Color color) { m_rect.setOutlineColor(color); }
void sfui::Button::setTextFont(const sf::Font& font) { m_text->setFont(font); }
void sfui::Button::setTextFont(const std::string& path) { m_text->setFont(path); }
void sfui::Button::setText(const sf::String& text) { m_text->setText(text); }
void sfui::Button::setTextCharacterSize(unsigned int size) { m_text->setCharacterSize(size); }
void sfui::Button::setTextLineSpacing(float spacing_factor) { m_text->setLineSpacing(spacing_factor); }
void sfui::Button::setTextLetterSpacing(float spacing_factor) { m_text->setLetterSpacing(spacing_factor); }
void sfui::Button::setTextStyle(uint32_t style) { m_text->setStyle(style); }
void sfui::Button::setTextFillColor(sf::Color color) { m_text->setFillColor(color); }
void sfui::Button::setTextOutlineColor(sf::Color color) { m_text->setOutlineColor(color); }
void sfui::Button::setTextOutlineThickness(float thickness) { m_text->setOutlineThickness(thickness); }
void sfui::Button::setOnPressedCallback(std::function<void()> callback) { m_on_pressed_callback = callback; }
void sfui::Button::setOnReleasedCallback(std::function<void()> callback) { m_on_released_callback = callback;}
void sfui::Button::setOnHoverCallback(std::function<void()> callback) { m_on_hover_callback = callback; }
void sfui::Button::centrateText() {
	m_text->setPosition({
		this->getPosition().x + (this->getSize().x - m_text->getSize().x) / 2.f,
		this->getPosition().y + (this->getSize().y - m_text->getSize().y) / 2.f
	});
}
sf::Vector2f sfui::Button::getPosition() { return m_rect.getPosition(); }
sf::Vector2f sfui::Button::getSize() { return m_rect.getSize(); }
sf::String sfui::Button::getText() { return m_text->getText(); }
bool sfui::Button::isPressed() { return m_is_pressed; }

void sfui::Button::onHover() {
	m_rect.setFillColor(m_hover_color);
	if (m_on_hover_callback != nullptr) m_on_hover_callback();
}

void sfui::Button::onPressed() {
	m_rect.setFillColor(m_fill_color);
	if (m_on_pressed_callback != nullptr) m_on_pressed_callback();
}

void sfui::Button::onReleased() {
	m_rect.setFillColor(m_hover_color);
	if (m_on_released_callback != nullptr) m_on_released_callback();
}