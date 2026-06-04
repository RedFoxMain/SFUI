#include "../../../include/SFUI/Label/label.hpp"

void sfui::Label::draw(sf::RenderTarget& target, sf::RenderStates states) const { 
	if (m_is_hidden) return;
	target.draw(*m_text, states); 
}
void sfui::Label::hide(bool hidden) { m_is_hidden = hidden; }
void sfui::Label::setPosition(sf::Vector2f position) { m_text->setPosition(position); }
void sfui::Label::setPositionX(float position_x) { m_text->setPosition({ position_x, m_text->getPosition().y }); }
void sfui::Label::setPositionY(float position_y) { m_text->setPosition({ m_text->getPosition().x, position_y }); }
void sfui::Label::setText(const sf::String& text) { m_text->setString(text); }
void sfui::Label::setCharacterSize(unsigned int size) { m_text->setCharacterSize(size); }
void sfui::Label::setLineSpacing(float spacing_factor) { m_text->setLineSpacing(spacing_factor); }
void sfui::Label::setLetterSpacing(float spacing_factor) { m_text->setLetterSpacing(spacing_factor); }
void sfui::Label::setStyle(uint32_t style) { m_text->setStyle(style); }
void sfui::Label::setFillColor(sf::Color color) { m_text->setFillColor(color); }
void sfui::Label::setOutlineColor(sf::Color color) { m_text->setOutlineColor(color); }
void sfui::Label::setOutlineThickness(float thickness) { m_text->setOutlineThickness(thickness); }
void sfui::Label::setFont(const sf::Font& font) { 
	m_font = font;
	m_text->setFont(m_font); 
}
void sfui::Label::setFont(const std::string& path) { 
	if (!std::filesystem::exists(path)) throw std::runtime_error("Can't find font by path: " + path);
	if(!m_font.openFromFile(path)) throw std::runtime_error("Can't load font");
	m_text->setFont(m_font); 
}

sf::String sfui::Label::getText() { return m_text->getString(); }
sf::Font sfui::Label::getFont() { return m_text->getFont(); }
unsigned int sfui::Label::getCharacterSize() { return m_text->getCharacterSize(); }
float sfui::Label::getLetterSpacing() { return m_text->getLetterSpacing(); }
float sfui::Label::getLineSpacing() { return m_text->getLineSpacing(); }
uint32_t sfui::Label::getStyle() { return m_text->getStyle(); }
sf::Color sfui::Label::getFillColor() { return m_text->getFillColor(); }
sf::Color sfui::Label::getOutlineColor() { return m_text->getOutlineColor(); }
float sfui::Label::getOutlineThickness() { return m_text->getOutlineThickness(); }
sf::Vector2f sfui::Label::findCharacterPos(std::size_t index) { return m_text->findCharacterPos(index); }
sf::Vector2f sfui::Label::getPosition() { return m_text->getPosition(); }
sf::Vector2f sfui::Label::getSize() { return m_text->getLocalBounds().size; }