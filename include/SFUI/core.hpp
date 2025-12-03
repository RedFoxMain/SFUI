#ifndef SFUI_CORE_HPP
#define SFUI_CORE_HPP

#include <vector>
#include <algorithm>

#include "widget.hpp"

#include "Button/button.hpp"
#include "Button/check_box.hpp"
#include "Button/radio_button.hpp"
#include "TextBox/text_box.hpp"
#include "ProgressBar/progress_bar.hpp"
#include "Range/range.hpp"
#include "Text/text.hpp"
#include "Layout/layout.hpp"
#include "Window/window.hpp"

namespace sfui {
	class Canvas {
	public:
		Layout* layout;

	public:
		Canvas(sf::Vector2f size, sf::Vector2f position = {0, 0}, bool hide = false)
			: layout(new DefaultLayout(size, position, hide)) {
		}
		~Canvas() {
			delete layout;
		}

		/// <summary>
		/// Display all Widgets in the SFML Window
		/// </summary>
		/// <param name="wnd"></param>
		void draw(sf::RenderWindow* wnd);

		/// <summary>
		/// Handle all Events
		/// </summary>
		/// <param name="event"></param>
		void processEvents(const sf::Event& event);
	};
}
#endif // !SFUI_CORE_HPP