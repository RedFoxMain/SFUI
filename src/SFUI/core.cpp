#include "../../include/SFUI/core.hpp"

void sfui::Canvas::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	if (m_controls.size() == 0 || m_is_hidden) return;
	for (std::shared_ptr<Widget> widget : m_controls)
		target.draw(*widget, states);
}

void sfui::Canvas::processEvents(const sf::Event& event) {
	if (m_controls.size() == 0 || m_is_hidden) return;
	for (std::shared_ptr<Widget> widget : m_controls)
		if (Processable* processable = dynamic_cast<Processable*>(widget.get()))
			processable->processEvents(event);
}

void sfui::Canvas::update(const sf::RenderWindow& window) {
	if (m_controls.size() == 0 || m_is_hidden) return;
	sf::Vector2u window_size = window.getSize();
	for (std::shared_ptr<Widget> widget : m_controls) {
		if (!Container::widgetInBounds(widget, window_size))
			Container::setWidgetInBounds(widget, window_size);
		if (Updatable* updatable = dynamic_cast<Updatable*>(widget.get()))
			updatable->update(window);
	}
}

void sfui::Canvas::hide(bool hidden) { m_is_hidden = hidden; }

void sfui::Canvas::addChild(std::shared_ptr<Widget> widget) {
	m_controls.push_back(widget);
}

void sfui::Canvas::addChild(std::vector<std::shared_ptr<Widget>> widgets) {
	for (std::shared_ptr<Widget> widget : widgets) m_controls.push_back(widget);
}

void sfui::Canvas::removeChild(std::shared_ptr<Widget> widget) {
	std::vector<std::shared_ptr<Widget>>::iterator it = std::find(m_controls.begin(), m_controls.end(), widget);
	if (it != m_controls.end()) m_controls.erase(it);
}

void sfui::Canvas::removeChild(std::vector<std::shared_ptr<Widget>> widgets) {
	for (std::shared_ptr<Widget> widget : widgets) removeChild(widget);
}