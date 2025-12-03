#include "../../../include/SFUI/Layout/default_layout.hpp"

void sfui::DefaultLayout::update() {
	for (Widget* widget : getControls()) {
		if (widget->getPosition().x >= getPosition().x + getSize().x)
			widget->setPosition({ getPosition().x + getSize().x - widget->getSize().x, widget->getPosition().y });
		else if (widget->getPosition().x < getPosition().x)
			widget->setPosition({ getPosition().x, widget->getPosition().y });
		else if (widget->getPosition().y - widget->getSize().y >= getPosition().y + getSize().y)
			widget->setPosition({ widget->getPosition().x, getPosition().y + getSize().y - widget->getSize().y });
		else if (widget->getPosition().y < getPosition().y)
			widget->setPosition({ widget->getPosition().x, getPosition().y });
	}
}