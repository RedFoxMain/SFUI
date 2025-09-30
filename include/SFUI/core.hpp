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

namespace sfui {
	class Canvas {
	friend class Window;
	friend void Widget::draw(sf::RenderWindow* wnd);
	private:
		std::vector<Widget*> m_controls;
		bool m_is_hidden;

	public:
		Canvas(): m_is_hidden(false) {}
		~Canvas() {}

		/// <summary>
		/// Hide or show Canvas
		/// </summary>
		/// <param name="flag"></param>
		void hideCanvas(bool flag);

		/// <summary>
		/// Add new Widget to the Screen
		/// </summary>
		/// <param name="control"></param>
		void add(Widget* control);

		/// <summary>
		/// Add a bunch of Widgets to the Screen
		/// </summary>
		/// <param name="controls"></param>
		void add(const std::vector<Widget*> controls);

		/// <summary>
		/// Remove new Widget from the Screen
		/// </summary>
		/// <param name="control"></param>
		void remove(Widget* control);

		/// <summary>
		/// Remove a bunch of Widgets from the Screen
		/// </summary>
		/// <param name="controls"></param>
		void remove(const std::vector<Widget*> controls);

		/// <summary>
		/// Display all Widgets in the SFML Window
		/// </summary>
		/// <param name="wnd"></param>
		void render(sf::RenderWindow* wnd);

		/// <summary>
		/// Handle all Events
		/// </summary>
		/// <param name="event"></param>
		void processEvents(const sf::Event& event);
	};
}
#endif // !SFUI_CORE_HPP

