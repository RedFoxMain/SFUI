#ifndef SFUI_IMAGE_HPP
#define SFUI_IMAGE_HPP

#include <filesystem>
#include <memory>
#include <string>
#include "../widget.hpp"

namespace sfui {
	class Image: public Widget {
	private:
		sf::Texture m_image_texture;
		std::unique_ptr<sf::Sprite> m_image;
		bool m_is_hidden;

	public:
		Image(const std::string& path): m_is_hidden(false) {
			if (!std::filesystem::exists(path)) throw std::runtime_error("Can't find image: " + path);
			m_image_texture.loadFromFile(path);
			m_image = std::unique_ptr<sf::Sprite>(new sf::Sprite(m_image_texture));
		}
		~Image() override {}

		void loadFromFile(const std::string& path);
		void hide(bool hidden) override;
		void setPosition(sf::Vector2f position) override;
		void setPositionX(float position_x);
		void setPositionY(float position_y);
		void setSize(sf::Vector2f size);
		sf::Vector2f getPosition() override;
		sf::Vector2f getSize() override;

	private:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	};
}
#endif // !SFUI_IMAGE_HPP