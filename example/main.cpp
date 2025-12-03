#include <iostream>
#include "SFUI/core.hpp"
#include "SFUI/Window/window.hpp"

// TODO: ÄÎÄÅËÀÉ TextBox
int main() {
	sf::RenderWindow* main_wnd = new sf::RenderWindow(sf::VideoMode({ 800, 500 }), "SFUI test");
	sf::Font font("ArialRegular.ttf"); // Create Font
	
	// Create Progress bar
	sfui::ProgressBar* progress_bar = new sfui::ProgressBar();
	progress_bar->setSize({ 200, 20 });
	progress_bar->setValue(45);

	// Create Range
	sfui::Range* range = new sfui::Range();
	range->slider->setFillColor(sf::Color(128, 128, 128));
	range->setPositionY(progress_bar->getPosition().y + 30);

	// Ceate Text
	sfui::Text* progress_bar_value = new sfui::Text(font, "", 16);
	progress_bar_value->setPositionX(progress_bar->getSize().x + 10);
	progress_bar_value->setFillColor(sf::Color::White);

	// Create TextBox
	sfui::TextBox* text_box = new sfui::TextBox(new sfui::Text(font, "Enter text...", 16));
	text_box->setSize({ 200, 50 });

	// Create Button
	sfui::Button* btn = new sfui::Button(new sfui::Text(font, "Press", 18), [&]() {
		std::cout << text_box->getText() << std::endl;
	});
	btn->setPositionY(30);

	// Create Window
	sfui::Window* wnd = new sfui::Window(new sfui::Text(font, "Test window", 16));
	wnd->setPosition({ 200, 100 });

	// Create CheckBox and RadioButton
	sfui::CheckBox* check_box;
	sfui::RadioButton* radio_btn;

	check_box = new sfui::CheckBox(true, [&]() {
		radio_btn->setStatus(false);
		wnd->hideWindow(false);
	});
	check_box->setPosition({ 10, 70 });

	radio_btn = new sfui::RadioButton(false, [&]() {
		check_box->setStatus(false);
		wnd->hideWindow(true);
	});
	radio_btn->setPosition({ 50, 70 });

	wnd->layout->add({ btn, text_box }); // Add button and text box to window layout

	// Create Canvas to display all UI
	sfui::Canvas canvas(sf::Vector2f(main_wnd->getSize()));
	canvas.layout->add({ progress_bar, progress_bar_value, range, check_box, radio_btn });
	canvas.layout->add(wnd);
	// canvas.layout->hideLayout(true);
	while (main_wnd->isOpen()) {
		while (const auto event = main_wnd->pollEvent()) {
			if (event->is<sf::Event::Closed>()) main_wnd->close();
			canvas.processEvents(*event); // Handle canvas Events
		}
		main_wnd->clear(sf::Color(25, 25, 25));
		canvas.draw(main_wnd); // Draw Canvas
		// Your code goes here...
		progress_bar->setValue(range->getValue());
		progress_bar_value->setText(std::to_string(static_cast<int>(progress_bar->getValue())));
		main_wnd->display();
	}
}