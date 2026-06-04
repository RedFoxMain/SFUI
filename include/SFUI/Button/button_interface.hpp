#ifndef SFUI_BUTTON_INTERFACE_HPP
#define SFUI_BUTTON_INTERFACE_HPP

#include <functional>

namespace sfui {
	class ButtonBase {
	public:
		virtual void setOnPressedCallback(std::function<void()> callback) = 0;
		virtual void setOnReleasedCallback(std::function<void()> callback) = 0;
		virtual void setOnHoverCallback(std::function<void()> callback) = 0;
	};
}
#endif // !SFUI_BUTTON_INTERFACE_HPP