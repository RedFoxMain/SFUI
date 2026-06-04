#ifndef SFUI_CORE_HPP
#define SFUI_CORE_HPP

#include <vector>
#include "widget.hpp"

namespace sfui {
	class Canvas: public Container, public Updatable, public Processable {
	private:
		std::vector<std::shared_ptr<Widget>> m_controls;
		bool m_is_hidden;

	public:
		Canvas(sf::Vector2f size): m_is_hidden(false) {}
		~Canvas() { m_controls.clear(); }
		void hide(bool hidden);

		void addChild(std::shared_ptr<Widget> widget) override;
		void addChild(std::vector<std::shared_ptr<Widget>> widgets) override;
		void removeChild(std::shared_ptr<Widget> widget) override;
		void removeChild(std::vector<std::shared_ptr<Widget>> widgets) override;

		void processEvents(const sf::Event& event) override;
		void update(const sf::RenderWindow& window) override;

	private:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	};
}
#endif // !SFUI_CORE_HPP