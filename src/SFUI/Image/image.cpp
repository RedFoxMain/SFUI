#include "../../../include/SFUI/Image/image.hpp"

void sfui::Image::loadFromFile(const std::string& path) {
	if (!std::filesystem::exists(path)) throw std::runtime_error("Can't find image: " + path);
	m_image_texture.loadFromFile(path);
	m_image->setTexture(m_image_texture);
}

void sfui::Image::hide(bool hidden) { m_is_hidden = hidden; }
void sfui::Image::setPosition(sf::Vector2f position) { m_image->setPosition(position); }
void sfui::Image::setPositionX(float position_x) { m_image->setPosition({ position_x, m_image->getPosition().y }); }
void sfui::Image::setPositionY(float position_y) { m_image->setPosition({ m_image->getPosition().x, position_y }); }
void sfui::Image::setSize(sf::Vector2f size) {
	m_image->setScale(sf::Vector2f(
		size.x / static_cast<float>(m_image_texture.getSize().x),
		size.y / static_cast<float>(m_image_texture.getSize().y)
	));
}
sf::Vector2f sfui::Image::getPosition() { return m_image->getPosition(); }
sf::Vector2f sfui::Image::getSize() {
	return sf::Vector2f(
		m_image->getTexture().getSize().x * m_image->getScale().x,
		m_image->getTexture().getSize().y * m_image->getScale().y
	);
}

void sfui::Image::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	if (m_is_hidden) return;
	target.draw(*m_image, states);
}