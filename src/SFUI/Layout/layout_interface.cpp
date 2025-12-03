#include "../../../include/SFUI/Layout/layout_interface.hpp"
#include "../Window/window.hpp"
#include "../core.hpp"

void sfui::Layout::setSize(sf::Vector2f size) {
	m_size = size;
}

void sfui::Layout::setSizeX(float size_x) {
	m_size.x = size_x;
}

void sfui::Layout::setSizeY(float size_y) {
	m_size.y = size_y;
}

void sfui::Layout::setPosition(sf::Vector2f position) {
	m_position = position;
}

void sfui::Layout::setPositionX(float position_x) {
	m_position.x = position_x;
}

void sfui::Layout::setPositionY(float position_y) {
	m_position.y = position_y;
}

sf::Vector2f sfui::Layout::getSize() {
	return m_size;
}

sf::Vector2f sfui::Layout::getPosition() {
	return m_position;
}

bool sfui::Layout::isHidden() {
	return m_is_hidden;
}

std::vector<sfui::Widget*> sfui::Layout::getControls() {
	return m_controls;
}

void sfui::Layout::hideLayout(bool flag) {
	m_is_hidden = flag;
}

void sfui::Layout::add(Widget* widget) {
	widget->m_base_position = widget->getPosition();
	widget->setPosition(m_position + widget->getPosition());
	m_controls.push_back(widget);
}

void sfui::Layout::add(const std::vector<Widget*> controls) {
	for (Widget* widget: controls) {
		widget->m_base_position = widget->getPosition();
		widget->setPosition(m_position + widget->getPosition());
		m_controls.push_back(widget);
	}
}

void sfui::Layout::remove(Widget* control) {
	std::vector<Widget*>::iterator it = std::find(m_controls.begin(), m_controls.end(), control);
	if (it != m_controls.end()) m_controls.erase(it);
}

void sfui::Layout::remove(const std::vector<Widget*> controls) {
	for (auto* element : m_controls) {
		std::vector<Widget*>::iterator it = std::find(m_controls.begin(), m_controls.end(), element);
		if (it != m_controls.end()) m_controls.erase(it);
	}
}
void sfui::Layout::draw(sf::RenderWindow* wnd) {
	if (m_is_hidden) return;
	for (Widget* widget : getControls()) {
		if (Button* btn_ptr = dynamic_cast<Button*>(widget)) btn_ptr->draw(wnd);
		if (Text* text_ptr = dynamic_cast<Text*>(widget)) text_ptr->draw(wnd);
		if (ProgressBar* progress_bar_ptr = dynamic_cast<ProgressBar*>(widget)) progress_bar_ptr->draw(wnd);
		if (CheckBox* check_box_ptr = dynamic_cast<CheckBox*>(widget)) check_box_ptr->draw(wnd);
		if (RadioButton* radio_btn_ptr = dynamic_cast<RadioButton*>(widget)) radio_btn_ptr->draw(wnd);
		if (Range* range_ptr = dynamic_cast<Range*>(widget)) range_ptr->draw(wnd);
		if (TextBox* input_field_ptr = dynamic_cast<TextBox*>(widget)) input_field_ptr->draw(wnd);
		if (Window* window_ptr = dynamic_cast<Window*>(widget)) if (!window_ptr->isClosed()) window_ptr->draw(wnd);
	}
}

void sfui::Layout::processEvents(const sf::Event& event) {
	if (m_is_hidden) return;
	for (Widget* widget : getControls()) {
		if (Button* btn_ptr = dynamic_cast<Button*>(widget))
			if (btn_ptr->m_is_enabled) btn_ptr->processEvents(event);
		if (CheckBox* check_box_ptr = dynamic_cast<CheckBox*>(widget))
			if (check_box_ptr->m_is_enabled) check_box_ptr->processEvents(event);
		if (RadioButton* radio_btn_ptr = dynamic_cast<RadioButton*>(widget))
			if (radio_btn_ptr->m_is_enabled) radio_btn_ptr->processEvents(event);
		if (Range* range_ptr = dynamic_cast<Range*>(widget))
			if (range_ptr->slider->m_is_enabled) range_ptr->processEvents(event);
		if (TextBox* input_field_ptr = dynamic_cast<TextBox*>(widget))
			if (input_field_ptr->m_is_enabled) input_field_ptr->processEvents(event);
		if (Window* window_ptr = dynamic_cast<Window*>(widget))
			if(window_ptr->m_is_enabled) window_ptr->processEvents(event);
	}
}