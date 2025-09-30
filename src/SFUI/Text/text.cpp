#include "../../../include/SFUI/Text/text.hpp"

void sfui::Text::draw(sf::RenderWindow* wnd) {
	wnd->draw(*m_text);
}

void sfui::Text::setOrigin(sf::Vector2f origin) {
	m_text->setOrigin(origin);
}

void sfui::Text::setPosition(sf::Vector2f position) {
	m_text->setPosition(position);
}

void sfui::Text::setPositionX(float position_x) {
	m_text->setPosition({ position_x, m_text->getPosition().y });
}

void sfui::Text::setPositionY(float position_y) {
	m_text->setPosition({ m_text->getPosition().x, position_y });
}

void sfui::Text::setRotation(sf::Angle angle) {
	m_text->setRotation(angle);
}

void sfui::Text::setFont(const sf::Font& font) {
	m_text->setFont(font);
}

void sfui::Text::setString(const sf::String& string) {
	m_text->setString(string);
}

void sfui::Text::setCharacterSize(unsigned int size) {
	m_text->setCharacterSize(size);
}

void sfui::Text::setLineSpacing(float spacing_factor) {
	m_text->setLineSpacing(spacing_factor);
}

void sfui::Text::setLetterSpacing(float spacing_factor) {
	m_text->setLetterSpacing(spacing_factor);
}

void sfui::Text::setStyle(uint32_t style) {
	m_text->setStyle(style);
}

void sfui::Text::setFillColor(sf::Color color) {
	m_text->setFillColor(color);
}

void sfui::Text::setOutlineColor(sf::Color color) {
	m_text->setOutlineColor(color);
}

void sfui::Text::setOutlineThickness(float thickness) {
	m_text->setOutlineThickness(thickness);
}

sf::Vector2f sfui::Text::getPosition() {
	return m_text->getPosition();
}

sf::Angle sfui::Text::getRotation() {
	return m_text->getRotation();
}

sf::String sfui::Text::getString() {
	return m_text->getString();
}

sf::Vector2f sfui::Text::getOrigin() {
	return m_text->getOrigin();
}

sf::Font sfui::Text::getFont() {
	return m_text->getFont();
}

unsigned int sfui::Text::getCharacterSize() {
	return m_text->getCharacterSize();
}

float sfui::Text::getLetterSpacing() {
	return m_text->getLetterSpacing();
}

float sfui::Text::getLineSpacing() {
	return m_text->getLineSpacing();
}

uint32_t sfui::Text::getStyle() {
	return m_text->getStyle();
}

sf::Color sfui::Text::getFillColor() {
	return m_text->getFillColor();
}

sf::Color sfui::Text::getOutlineColor() {
	return m_text->getOutlineColor();
}

float sfui::Text::getOutlineThickness() {
	return m_text->getOutlineThickness();
}

sf::Vector2f sfui::Text::findCharacterPos(std::size_t index) {
	return m_text->findCharacterPos(index);
}

sf::FloatRect sfui::Text::getLocalBounds() {
	return m_text->getLocalBounds();
}

sf::FloatRect sfui::Text::getGlobalBounds() {
	return m_text->getGlobalBounds();
}