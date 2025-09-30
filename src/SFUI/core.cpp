#include "../../include/SFUI/core.hpp"
#include "../../include/SFUI/Window/window.hpp"

void sfui::Canvas::hideCanvas(bool flag) {
	m_is_hidden = flag;
}

void sfui::Canvas::add(Widget* widget) {
	widget->is_drawable = true;
	m_controls.push_back(widget);
}

void sfui::Canvas::add(const std::vector<Widget*> controls) {
	m_controls.insert(m_controls.end(), controls.begin(), controls.end());
}

void sfui::Canvas::remove(Widget* control) {
	std::vector<Widget*>::iterator it = std::find(m_controls.begin(), m_controls.end(), control);
	if(it != m_controls.end()) m_controls.erase(it);
}

void sfui::Canvas::remove(const std::vector<Widget*> controls) {
	for (auto* element : m_controls) {
		std::vector<Widget*>::iterator it = std::find(m_controls.begin(), m_controls.end(), element);
		if (it != m_controls.end()) m_controls.erase(it);
	}
}

void sfui::Canvas::render(sf::RenderWindow* wnd) {
	if (m_is_hidden) return;
	for (Widget* element : m_controls)
		if(element->is_drawable) element->draw(wnd);
}

void sfui::Canvas::processEvents(const sf::Event& event) {
	if (m_is_hidden) return;
	for (std::vector<Widget*>::iterator element = m_controls.begin(); element != m_controls.end(); ++element) {
		if (Button* btn_ptr = dynamic_cast<Button*>(*element))
			btn_ptr->processEvents(event);
		if (CheckBox* check_box_ptr = dynamic_cast<CheckBox*>(*element))
			check_box_ptr->processEvents(event);
		if (RadioButton* radio_btn_ptr = dynamic_cast<RadioButton*>(*element))
			radio_btn_ptr->processEvents(event);
		if (TextBox* input_field_ptr = dynamic_cast<TextBox*>(*element))
			input_field_ptr->processEvents(event);
		if (Range* range_ptr = dynamic_cast<Range*>(*element))
			range_ptr->processEvents(event);
		if (Window* window_ptr = dynamic_cast<Window*>(*element)) {
			window_ptr->processEvents(event);
			if(window_ptr->is_closed_) (*element)->is_drawable = false;
		}
	}
}