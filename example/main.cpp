#include "SFUI/core.hpp"
#include "SFUI/Window/window.hpp"

int main() {
	sf::RenderWindow* main_wnd = new sf::RenderWindow(sf::VideoMode({ 800, 500 }), "SFUI test");
	sf::Font font("ArialRegular.ttf");
	
	// Create Progress bar
	sfui::ProgressBar* progress_bar = new sfui::ProgressBar();
	progress_bar->setSize({ 200, 10 });

	// Create Range
	sfui::Range* range = new sfui::Range();
	range->slider->setFillColor(sf::Color(128, 128, 128));
	range->setSize({ 200, 10 });
	range->setPositionY(15);

	// Ceate Text
	sfui::Text* text = new sfui::Text(font, "Value: ", 22);
	text->setPositionY(35);
	sfui::Text* progress_bar_value = new sfui::Text(font, "", 22);
	progress_bar_value->setPosition({ text->getGlobalBounds().size.x, 35 });

	// Create Button
	sfui::Button* btn = new sfui::Button(new sfui::Text(font, "Press", 18), [&]() {
		progress_bar_value->setString(std::to_string(static_cast<int>(progress_bar->getValue())));
	});
	btn->setPositionY(70);
	// Create Window
	sfui::Window* wnd = new sfui::Window(new sfui::Text(font, "Test window", 16));
	wnd->setPosition({ 200, 100 });
	wnd->add({ progress_bar, range });
	wnd->add({ text, progress_bar_value, btn });

	// Create CheckBox and RadioButton
	sfui::CheckBox* check_box;
	sfui::RadioButton* radio_btn;

	check_box = new sfui::CheckBox(true, [&]() {
		radio_btn->setStatus(false);
		wnd->hideWindow(false);
	});
	check_box->setPosition({ 5, 10 });

	radio_btn = new sfui::RadioButton(false, [&]() {
		check_box->setStatus(false);
		wnd->hideWindow(true);
	});
	radio_btn->setPosition({ 40, 10 });

	// Create TextBox
	sfui::TextBox* text_box = new sfui::TextBox(new sfui::Text(font, "Enter text..."));
	text_box->setPosition({ 70, 10 });

	// Create Canvas to display all UI
	sfui::Canvas canvas;
	canvas.add(wnd);
	canvas.add({ check_box, radio_btn, text_box });

	while (main_wnd->isOpen()) {
		while (const auto event = main_wnd->pollEvent()) {
			if (event->is<sf::Event::Closed>()) main_wnd->close();
			canvas.processEvents(*event); // Handle canvas events
		}
		main_wnd->clear(sf::Color(128, 128, 128));
		canvas.render(main_wnd); // Draw canvass
		progress_bar->setValue(range->getValue());
		main_wnd->display();
	}
}