#include "../../../include/SFUI/Window/window.hpp"

void sfui::Window::draw(sf::RenderWindow* wnd) {
	if (m_is_hidden) return;
	wnd->draw(m_rect);
	wnd->draw(m_tool_bar);
	m_title->draw(wnd);
	close_btn.draw(wnd);
	drawToolBar();
	m_canvas.render(wnd);
}

void sfui::Window::processEvents(const sf::Event& event) {
	if (m_is_hidden) return;
	if (const sf::Event::MouseButtonPressed* btn_pressed = event.getIf<sf::Event::MouseButtonPressed>()) {
		if (btn_pressed->button == sf::Mouse::Button::Left) {
			if (is_active_ = m_tool_bar.getGlobalBounds().contains(sf::Vector2f(btn_pressed->position))) {
				sf::Vector2f temp_pos = sf::Vector2f(btn_pressed->position);
				drag_offset_ = temp_pos - m_rect.getPosition();
				is_dragging_ = true;
			}
		}
	}

	if (const sf::Event::MouseButtonReleased* btn_pressed = event.getIf<sf::Event::MouseButtonReleased>()) {
		if (btn_pressed->button == sf::Mouse::Button::Left)
			is_active_ = is_dragging_ = false;
	}

	if (const sf::Event::MouseMoved* mouse = event.getIf<sf::Event::MouseMoved>()) {
		mouse_pos_ = sf::Vector2f(mouse->position);
		is_dragging_ = true;
		if (is_dragging_ && is_active_) {
			m_rect.setPosition(mouse_pos_ - drag_offset_);
			updateContentPosition();
		}
	}
	close_btn.processEvents(event);
	m_canvas.processEvents(event);
}

void sfui::Window::drawToolBar() {
	m_tool_bar.setPosition(m_rect.getPosition());
	m_title->setPosition(m_tool_bar.getPosition());
	close_btn.setPosition(m_tool_bar.getPosition() + sf::Vector2f(m_tool_bar.getSize().x - close_btn.getSize().x, 0));

	close_btn.setPosition({
		m_tool_bar.getPosition().x + m_tool_bar.getSize().x - close_btn.getSize().x - 3,
		m_tool_bar.getPosition().y + m_tool_bar.getSize().y / 2.f - close_btn.getSize().y / 2.f
	});
}

void sfui::Window::updateContentPosition() {
	for (Widget* element : m_canvas.m_controls) {
		element->setPosition(m_rect.getPosition() + sf::Vector2f(0, m_tool_bar.getSize().y + 1.5f) + element->m_base_offset);
	}
}

void sfui::Window::setWidgetToWindow(Widget* widget) {
	widget->m_base_offset = widget->getPosition();
	widget->setPosition({
		m_rect.getPosition().x + m_tool_bar.getPosition().x + widget->getPosition().x,
		m_rect.getPosition().y + m_tool_bar.getPosition().y + m_tool_bar.getSize().y + widget->getPosition().y + 1.5f
	});
}

void sfui::Window::add(Widget* widget) {
	setWidgetToWindow(widget);
	m_canvas.add(widget);
}

void sfui::Window::add(std::vector<Widget*> widgets) {
	for (Widget* widget : widgets) setWidgetToWindow(widget);
	m_canvas.add(widgets);
}

void sfui::Window::remove(Widget* widget) {
	m_canvas.remove(widget);
}

void sfui::Window::remove(std::vector<Widget*> widgets) {
	m_canvas.remove(widgets);
}

void sfui::Window::hideWindow(bool flag) {
	m_is_hidden = flag;
}

void sfui::Window::setPosition(sf::Vector2f position) {
	m_rect.setPosition(position);
	updateContentPosition();
}

void sfui::Window::setPositionX(float position_x) {
	m_rect.setPosition({ position_x, m_rect.getPosition().y });
}

void sfui::Window::setPositionY(float position_y) {
	m_rect.setPosition({m_rect.getPosition().x, position_y });
}

void sfui::Window::setSize(sf::Vector2f size) {
	m_rect.setSize(size);
}

void sfui::Window::setSizeX(float size_x) {
	m_rect.setSize({ size_x, m_rect.getSize().y });
}

void sfui::Window::setSizeY(float size_y) {
	m_rect.setSize({ m_rect.getSize().x, size_y });
}

void sfui::Window::setWindowColor(sf::Color color) {
	m_rect.setFillColor(color);
}

sf::Vector2f sfui::Window::getPosition() {
	return m_rect.getPosition();
}

bool sfui::Window::isClosed() {
	return is_closed_;
}