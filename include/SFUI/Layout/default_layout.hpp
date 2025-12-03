#ifndef SFUI_DEFAULT_LAYOUT_HPP
#define SFUI_DEFAULT_LAYOUT_HPP

#include "layout_interface.hpp"

namespace sfui {
	class DefaultLayout: public Layout {
	public:
		using Layout::Layout;
		void update() override;
	};
}
#endif // !SFUI_DEFAULT_LAYOUT_HPP