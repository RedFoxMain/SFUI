#ifndef SFUI_WINDOW_HPP
#define SFUI_WINDOW_HPP

#include "../core.hpp"

namespace sfui {
	namespace WindowStyle {
		enum Style: uint8_t { DEFAULT = 1, RESIZABLE = 1 << 1 };
	}
	class Window: public Widget {
	friend class Canvas;
	public:
		Button close_btn;

	private:
		Canvas m_canvas;
		Text* m_title;
		sf::Font font;

		sf::RectangleShape m_rect;
		sf::RectangleShape m_tool_bar;

		sf::Vector2f drag_offset_;
		sf::Vector2f mouse_pos_;
		bool m_is_hidden;
		bool is_closed_;
		bool is_active_;
		bool is_dragging_;

		uint8_t m_style;

	public:
		Window(Text* title, uint8_t style = WindowStyle::DEFAULT, sf::Vector2f size = { 300, 200 }, sf::Vector2f position = { 0 , 0 })
			: is_active_(false), is_dragging_(false), m_is_hidden(false), is_closed_(false), m_title(title) {
			m_rect.setPosition(position);
			m_rect.setSize(size);
			m_rect.setOutlineThickness(1);
			m_rect.setOutlineColor(sf::Color::Black);
			m_rect.setFillColor(sf::Color::Black);
			
			m_tool_bar.setSize({ m_rect.getSize().x, m_rect.getSize().y / 10.f });
			m_tool_bar.setPosition(m_rect.getPosition());
			m_tool_bar.setFillColor(sf::Color::White);
			m_rect.setOutlineColor(sf::Color::Black);

			font = title->getFont();
			m_title->setFillColor(sf::Color::Black);

			close_btn.setSize({ m_tool_bar.getSize().y - 5, m_tool_bar.getSize().y - 5 });
			close_btn.text = new Text(font, "X", m_tool_bar.getSize().y - 5);
			close_btn.text->setFillColor(sf::Color::Black);
			close_btn.setHoverColor(sf::Color(128, 128, 128));
			close_btn.setOnPressedCallback([&]() {
				is_closed_ = true;
			});
		}
		~Window() {
			delete m_title;
			m_canvas.~Canvas();
		}

		/// <summary>
		/// Add new Widget to the Window
		/// </summary>
		/// <param name="widget"></param>
		void add(Widget* widget);

		/// <summary>
		/// Add a bunch of new Widgets to the Window
		/// </summary>
		/// <param name="widgets"></param>
		void add(std::vector<Widget*> widgets);

		/// <summary>
		/// Remove a Widget from the Window
		/// </summary>
		/// <param name="widget"></param>
		void remove(Widget* widget);

		/// <summary>
		///  Remove a bunch of Widgets from the Window
		/// </summary>
		/// <param name="widgets"></param>
		void remove(std::vector<Widget*> widgets);

		/// <summary>
		/// Show or hide window
		/// </summary>
		/// <param name="flag"></param>
		void hideWindow(bool flag);

		/// <summary>
		/// Set position by x and y
		/// </summary>
		/// <param name="position"></param>
		void setPosition(sf::Vector2f position) override;

		/// <summary>
		/// Set position by x
		/// </summary>
		/// <param name="position_x"></param>
		void setPositionX(float position_x);

		/// <summary>
		/// Set position by y
		/// </summary>
		/// <param name="position_y"></param>
		void setPositionY(float position_y);

		/// <summary>
		/// Set sizes by x and y
		/// </summary>
		/// <param name="size"></param>
		void setSize(sf::Vector2f size);

		/// <summary>
		/// Set sizes by x
		/// </summary>
		/// <param name="size_x"></param>
		void setSizeX(float size_x);

		/// <summary>
		/// Set sizes by y
		/// </summary>
		/// <param name="size_y"></param>
		void setSizeY(float size_y);

		/// <summary>
		/// Set Window color
		/// </summary>
		/// <param name="color"></param>
		void setWindowColor(sf::Color color);

		/// <summary>
		/// Return the the Window position
		/// </summary>
		/// <returns>sf::Vector2f</returns>
		sf::Vector2f getPosition() override;

		/// <summary>
		/// Check if Window is closed
		/// </summary>
		/// <returns>bool</returns>
		bool isClosed();

	private:
		void draw(sf::RenderWindow* wnd) override;
		void processEvents(const sf::Event& event);

		void drawToolBar();
		void updateContentPosition();
		void setWidgetToWindow(Widget* widget);
	};
}
#endif // !SFUI_WINDOW_HPP