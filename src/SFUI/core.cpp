#include "../../include/SFUI/core.hpp"
#include "../../include/SFUI/Window/window.hpp"

void sfui::Canvas::draw(sf::RenderWindow* wnd) {
	layout->draw(wnd);
	layout->update();
}

void sfui::Canvas::processEvents(const sf::Event& event) {
	layout->processEvents(event);
}