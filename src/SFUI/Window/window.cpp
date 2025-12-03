#include "../../../include/SFUI/Window/window.hpp"

void sfui::Window::draw(sf::RenderWindow* wnd) {
	if (m_is_hidden) return;
	wnd->draw(m_rect);
	drawToolBar(wnd);
	layout->update();
	layout->draw(wnd);
}

void sfui::Window::processEvents(const sf::Event& event) {
	if (m_is_hidden) return;
	if (const sf::Event::MouseButtonPressed* btn_pressed = event.getIf<sf::Event::MouseButtonPressed>()) {
		if (btn_pressed->button == sf::Mouse::Button::Left) {
			if (m_style != WindowStyle::NO_COLLAPSE) {
				if (is_active_ = m_tool_bar.getGlobalBounds().contains(sf::Vector2f(btn_pressed->position))) {
					sf::Vector2f temp_pos = sf::Vector2f(btn_pressed->position);
					drag_offset_ = temp_pos - m_rect.getPosition();
					is_dragging_ = true;
				}
			}
		}
	}

	if (const sf::Event::MouseButtonReleased* btn_pressed = event.getIf<sf::Event::MouseButtonReleased>()) {
		if (btn_pressed->button == sf::Mouse::Button::Left) {
			is_active_ = is_dragging_ = false;
		}
	}

	if (const sf::Event::MouseMoved* mouse = event.getIf<sf::Event::MouseMoved>()) {
		mouse_pos_ = sf::Vector2f(mouse->position);
		is_dragging_ = true;
		if (is_dragging_ && is_active_) {
			setPosition(mouse_pos_ - drag_offset_);
			for (Widget* widget : layout->getControls()) {
				widget->setPosition(m_rect.getPosition() + sf::Vector2f(0, m_tool_bar.getSize().y + 2) + widget->m_base_position);
			}
		}
	}
	close_btn->processEvents(event);
	layout->processEvents(event);
}

void sfui::Window::drawToolBar(sf::RenderWindow* wnd) {
	if (m_style == WindowStyle::NO_TITLE_BAR) return;
	wnd->draw(m_tool_bar);
	m_title->draw(wnd);
	close_btn->draw(wnd);
	m_tool_bar.setPosition(m_rect.getPosition());
	m_tool_bar.setSize({ m_rect.getSize().x, m_rect.getSize().y / 10.f });
	m_title->setPosition(m_tool_bar.getPosition());
	close_btn->setPosition(m_tool_bar.getPosition() + sf::Vector2f(m_tool_bar.getSize().x - close_btn->getSize().x, 0));

	close_btn->setPosition({
		m_tool_bar.getPosition().x + m_tool_bar.getSize().x - close_btn->getSize().x - 3,
		m_tool_bar.getPosition().y + m_tool_bar.getSize().y / 2.f - close_btn->getSize().y / 2.f
	});
}

void sfui::Window::hideWindow(bool flag) {
	m_is_hidden = flag;
}

void sfui::Window::setEnabled(bool flag) {
	m_is_enabled = flag;
}
	
void sfui::Window::setPosition(sf::Vector2f position) {
	m_rect.setPosition(position);
	layout->setPosition(sf::Vector2f(
		position.x, (m_style != WindowStyle::NO_TITLE_BAR) ? position.y + m_tool_bar.getSize().y + 2 : position.y
	));
}

void sfui::Window::setPositionX(float position_x) {
	m_rect.setPosition({ position_x, m_rect.getPosition().y });
	layout->setPositionX(position_x);
}

void sfui::Window::setPositionY(float position_y) {
	m_rect.setPosition({m_rect.getPosition().x, position_y });
	if (m_style == WindowStyle::NO_TITLE_BAR) layout->setPositionY(position_y);
	else layout->setPositionY(position_y + m_tool_bar.getSize().y + 2);
}

void sfui::Window::setSize(sf::Vector2f size) {
	m_rect.setSize(size);
	if (m_style == WindowStyle::NO_TITLE_BAR) layout->setSize(size);
	else layout->setSize(size - sf::Vector2f(0, m_tool_bar.getSize().y + 2));
}

void sfui::Window::setSizeX(float size_x) {
	m_rect.setSize({ size_x, m_rect.getSize().y });
	layout->setSizeX(size_x);
}

void sfui::Window::setSizeY(float size_y) {
	m_rect.setSize({ m_rect.getSize().x, size_y });
	if (m_style == WindowStyle::NO_TITLE_BAR) layout->setSizeY(size_y);
	else layout->setPositionY(size_y - m_tool_bar.getSize().y + 2);
	layout->setSizeX(size_y);
}

void sfui::Window::setWindowColor(sf::Color color) {
	m_rect.setFillColor(color);
}

sf::Vector2f sfui::Window::getPosition() {
	return m_rect.getPosition();
}

sf::Vector2f  sfui::Window::getSize() {
	return m_rect.getSize();
}

bool sfui::Window::isClosed() {
	return is_closed_;
}