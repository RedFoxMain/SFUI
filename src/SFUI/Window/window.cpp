#include "../../../include/SFUI/Window/window.hpp"

void sfui::Window::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	if (m_is_hidden) return;
	target.draw(m_rect, states);
	//if (m_style != WindowStyle::NO_TITLE_BAR) return;
	target.draw(m_tool_bar, states);
	target.draw(*m_title, states);
	target.draw(*m_close_btn, states);
	for (std::shared_ptr<Widget> widget : m_controls)
		target.draw(*widget, states);
}

void sfui::Window::processEvents(const sf::Event& event) {
	if (m_is_hidden || !m_is_enabled) return;
	for (std::shared_ptr<Widget> widget : m_controls)
		if (sfui::Processable* widget_ptr = dynamic_cast<sfui::Processable*>(widget.get()))
			widget_ptr->processEvents(event);
	if (sfui::Processable* btn_ptr = dynamic_cast<sfui::Processable*>(m_close_btn.get()))
		btn_ptr->processEvents(event);
	if (const sf::Event::MouseButtonPressed* btn_pressed = event.getIf<sf::Event::MouseButtonPressed>()) {
		if (btn_pressed->button == sf::Mouse::Button::Left) {
			if (m_style != WindowStyle::NO_COLLAPSE) {
				if (m_is_active = sfui::isMouseOver(m_tool_bar, sf::Vector2f(btn_pressed->position))) {
					sf::Vector2f temp_pos = sf::Vector2f(btn_pressed->position);
					drag_offset_ = temp_pos - m_rect.getPosition();
					m_is_dragging = true;
				}
			}
		}
	}
	if (const sf::Event::MouseButtonReleased* btn_pressed = event.getIf<sf::Event::MouseButtonReleased>()) {
		if (btn_pressed->button == sf::Mouse::Button::Left) {
			m_is_active = m_is_dragging = false;
		}
	}

	if (const sf::Event::MouseMoved* mouse = event.getIf<sf::Event::MouseMoved>()) {
		if (m_is_dragging && m_is_active) {
			this->setPosition(sf::Vector2f(mouse->position) - drag_offset_);
			for (std::shared_ptr<Widget> widget : m_controls) {
				widget->setPosition(m_rect.getPosition() + sf::Vector2f(0, m_tool_bar.getSize().y + 2));
			}
		}
	}
}

void sfui::Window::update(const sf::RenderWindow& window) {
	if (m_is_hidden || !m_is_enabled || !m_is_active) return;
	for (std::shared_ptr<Widget> widget : m_controls) {
		if (!Container::widgetInBounds(widget, window.getSize()))
			Container::setWidgetInBounds(widget, window.getSize());
		if (sfui::Updatable* widget_ptr = dynamic_cast<sfui::Updatable*>(widget.get()))
			widget_ptr->update(window);
	}
	if (sfui::Updatable* btn_ptr = dynamic_cast<sfui::Updatable*>(m_close_btn.get()))
		btn_ptr->update(window);
}

void sfui::Window::addChild(std::shared_ptr<Widget> widget) {
	widget->setPosition(m_rect.getPosition() + sf::Vector2f(0, m_tool_bar.getSize().y + 2));
	m_controls.push_back(widget);
}

void sfui::Window::addChild(std::vector<std::shared_ptr<Widget>> widgets) {
	for (std::shared_ptr<Widget> widget : widgets) addChild(widget);
}

void sfui::Window::removeChild(std::shared_ptr<Widget> widget) {
	std::vector<std::shared_ptr<Widget>>::iterator it = std::find(m_controls.begin(), m_controls.end(), widget);
	if (it != m_controls.end()) m_controls.erase(it);
}

void sfui::Window::removeChild(std::vector<std::shared_ptr<Widget>> widgets) {
	for (std::shared_ptr<Widget> widget : widgets) removeChild(widget);
}

void sfui::Window::hide(bool hidden) { m_is_hidden = hidden; }
void  sfui::Window::setSize(sf::Vector2f size) {
	m_rect.setSize(size);
	m_tool_bar.setSize(m_rect.getSize());
}
void sfui::Window::setPosition(sf::Vector2f position) { 
	m_rect.setPosition(position); 
	m_tool_bar.setPosition(m_rect.getPosition());
	m_title->setPosition(m_tool_bar.getPosition());
	m_close_btn->setPosition(m_tool_bar.getPosition() + sf::Vector2f(m_tool_bar.getSize().x - m_close_btn->getSize().x, 0));
}
sf::Vector2f sfui::Window::getPosition() { return m_rect.getPosition(); }
sf::Vector2f sfui::Window::getSize() { return m_rect.getSize(); }