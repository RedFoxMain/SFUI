#include <iostream>
#include "SFUI/core.hpp"
#include "SFUI/Label/label.hpp"
#include "SFUI/Button/button.hpp"
#include "SFUI/Button/check_box.hpp"
#include "SFUI/Button/radio_button.hpp"
#include "SFUI/ProgressBar/progress_bar.hpp"
#include "SFUI/Range/range.hpp"
#include "SFUI/TextBox/text_box.hpp"
#include "SFUI/Image/image.hpp"
#include "SFUI/Window/window.hpp"

int main() {
	sf::RenderWindow main_wnd(sf::RenderWindow(sf::VideoMode({ 800, 500 }), "SFUI test"));
	std::shared_ptr<sfui::Label> text = std::shared_ptr<sfui::Label>(new sfui::Label("test"));
	text->setFillColor(sf::Color::White);
	text->setPositionX(100);

	std::shared_ptr<sfui::ProgressBar> progress_bar = std::shared_ptr<sfui::ProgressBar>(new sfui::ProgressBar());
	progress_bar->setPositionY(300);

	std::shared_ptr<sfui::Button> btn = std::shared_ptr<sfui::Button>(new sfui::Button("Click me!", [&] {
		progress_bar->updateValue(10);
	}));
	btn->setPosition({ 200, 200 });
	btn->setText("NOT CLICK!");

	std::shared_ptr<sfui::CheckBox> check_box = std::shared_ptr<sfui::CheckBox>(new sfui::CheckBox());
	check_box->setPosition({ 10, 10 });

	std::shared_ptr<sfui::RadioButton> radio_btn = std::shared_ptr<sfui::RadioButton>(new sfui::RadioButton());
	radio_btn->setPosition({ 50, 10 });

	std::shared_ptr<sfui::Image> image = std::shared_ptr<sfui::Image>(new sfui::Image("resources/DemoManSamurai.jpg"));
	image->setPosition({ 100, 100 });
	image->setSize({ 100, 50 });

	std::shared_ptr<sfui::Range> range = std::shared_ptr<sfui::Range>(new sfui::Range());
	range->setPositionY(400);

	std::shared_ptr<sfui::TextBox> input = std::shared_ptr<sfui::TextBox>(new sfui::TextBox("Enter something here..."));

	std::shared_ptr<sfui::Window> window = std::shared_ptr<sfui::Window>(new sfui::Window("Simple Window"));
	window->addChild(input);
	// Create Canvas to display all UI
	sfui::Canvas canvas(sf::Vector2f(main_wnd.getSize()));
	canvas.addChild(text);
	canvas.addChild({ btn, check_box, radio_btn });
	canvas.addChild({ progress_bar, range, image } );
	canvas.addChild(window);

	while (main_wnd.isOpen()) {
		while (const auto event = main_wnd.pollEvent()) {
			if (event->is<sf::Event::Closed>()) main_wnd.close();
			canvas.processEvents(event.value());
		}
		main_wnd.clear(sf::Color(25, 25, 25));
		canvas.update(main_wnd);
		//std::cout << range->getValue() << std::endl;
		main_wnd.draw(canvas);
		main_wnd.display();
	}
}