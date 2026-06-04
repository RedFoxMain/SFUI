#ifndef SFUI_WINDOW_HPP
#define SFUI_WINDOW_HPP

#include <vector>
#include <string>
#include "../widget.hpp"
#include "../Label/label.hpp"
#include "../Button/button.hpp"

namespace sfui {
	enum WindowStyle {
		DEFAULT		 = 0,
		RESIZABLE	 = 1 << 0,
		NO_TITLE_BAR = 1 << 1,
		NO_COLLAPSE	 = 1 << 2
	};

	class Window: public Widget, public Container, public Updatable, public Processable {
	private:
		std::vector<std::shared_ptr<Widget>> m_controls;
		std::unique_ptr<Label> m_title;
		std::unique_ptr<Button> m_close_btn;
		WindowStyle m_style;

		sf::RectangleShape m_rect;
		sf::RectangleShape m_tool_bar;

		sf::Vector2f drag_offset_;
		bool m_is_dragging;
		bool m_is_hidden;
		bool m_is_enabled;
		bool m_is_closed;
		bool m_is_active;

	public:
		Window(const std::string& title, WindowStyle style = WindowStyle::DEFAULT, sf::Vector2f size = { 300, 200 }, sf::Vector2f position = {})
			: m_is_hidden(false), m_is_dragging(false), m_is_enabled(true), m_is_active(true),
			m_is_closed(false), m_title(new Label(title, 14)), m_style(style) {
			m_rect.setPosition(position);
			m_rect.setSize(size);
			m_rect.setOutlineThickness(1);
			m_rect.setOutlineColor(sf::Color::Black);
			m_rect.setFillColor(sf::Color::Black);

			if (!title.empty()) {
				m_tool_bar.setSize({ m_rect.getSize().x, m_rect.getSize().y / 10.f });
				m_tool_bar.setPosition(m_rect.getPosition());
				m_tool_bar.setFillColor(sf::Color::White);

				m_tool_bar.setPosition(m_rect.getPosition());
				m_tool_bar.setSize({ m_rect.getSize().x, m_rect.getSize().y / 10.f });
				m_title->setFillColor(sf::Color::Black);
				m_title->setPosition(m_tool_bar.getPosition());

				m_close_btn = std::unique_ptr<Button>(new Button("x", [&]() { m_is_closed = true; }));
				m_close_btn->setTextCharacterSize(static_cast<unsigned int>(m_tool_bar.getSize().y - 10));
				m_close_btn->setSize({ m_tool_bar.getSize().y - 5, m_tool_bar.getSize().y - 5 });
				m_close_btn->setTextFillColor(sf::Color::Black);
				m_close_btn->setFillColor(sf::Color::Transparent);
				m_close_btn->setOutlineThickness(0.f);
				m_close_btn->setPosition(m_tool_bar.getPosition() + sf::Vector2f(m_tool_bar.getSize().x - m_close_btn->getSize().x, 0));
			}
		}

		~Window() override {
			m_controls.clear();
		}

		void addChild(std::shared_ptr<Widget> widget) override;
		void addChild(std::vector<std::shared_ptr<Widget>> widgets) override;
		void removeChild(std::shared_ptr<Widget> widget) override;
		void removeChild(std::vector<std::shared_ptr<Widget>> widgets) override;

		void hide(bool hidden) override;
		void setPosition(sf::Vector2f position) override;
		void setSize(sf::Vector2f size);
		sf::Vector2f getPosition() override;
		sf::Vector2f getSize() override;

	private:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
		void processEvents(const sf::Event& event) override;
		void update(const sf::RenderWindow& window) override;
	};
}
#endif // !SFUI_WINDOW_HPP