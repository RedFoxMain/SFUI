#include "../../../include/SFUI/TextBox/text_box.hpp"

void sfui::TextBox::processEvents(const sf::Event& event) {
    if (const sf::Event::MouseButtonPressed* btn_pressed = event.getIf<sf::Event::MouseButtonPressed>()) {
        is_active_ = isMouseOver(static_cast<sf::Vector2f>(btn_pressed->position));
        draw_place_holder_ = (input_string_.empty() && !is_active_);
    }

    if (const sf::Event::KeyPressed* key = event.getIf<sf::Event::KeyPressed>()) {
        if (key->scancode == sf::Keyboard::Scancode::Enter) {
            is_active_ = false;
        }
    }

    if (const sf::Event::TextEntered* m_text_entered = event.getIf<sf::Event::TextEntered>()) {
        if (is_active_ && (static_cast<int>(m_text_entered->unicode) < 128)) {
            if (static_cast<int>(m_text_entered->unicode) == BAKSPACE_KEY) {
                if (!input_string_.empty()) {
                    input_string_.pop_back();
                    m_text->setText(input_string_);
                }
            } else {
                if (m_text->getGlobalBounds().size.x < m_rect.getGlobalBounds().size.x - glyph_size_ * 2.f) {
                    input_string_ += static_cast<char>(m_text_entered->unicode);
                    m_text->setText(input_string_);
                }
            }
            if (!input_string_.empty()) draw_place_holder_ = false;
            else draw_place_holder_ = true;
        }
    }
}

void sfui::TextBox::draw(sf::RenderWindow* wnd) {
    wnd->draw(m_rect);
    if (m_place_holder && (draw_place_holder_ && input_string_.empty())) m_place_holder->draw(wnd);
    if (m_text) m_text->draw(wnd);
    updateSize();
}

void sfui::TextBox::setEnabled(bool flag) {
    m_is_enabled = flag;
}

void sfui::TextBox::setTextColor(sf::Color color) {
    m_text->setFillColor(color);
}

void sfui::TextBox::setPlaceHolderText(const std::string& text) {
    m_place_holder->setText(text);
}

void sfui::TextBox::setText(const std::string& text) {
    input_string_ = text;
    m_text->setText(input_string_);
}

void sfui::TextBox::setPosition(sf::Vector2f position) {
    m_rect.setPosition(position);
    centrateText();
}

void sfui::TextBox::setPositionX(float position_x) {
    m_rect.setPosition({ position_x, m_rect.getPosition().y });
    centrateText();
}

void sfui::TextBox::setPositionY(float position_y) {
    m_rect.setPosition({ m_rect.getPosition().x, position_y });
    centrateText();
}

void sfui::TextBox::setSize(sf::Vector2f size) {
    m_rect.setSize(size);
    updateSize();
}

void sfui::TextBox::setSizeX(float size_x) {
    m_rect.setSize({ size_x, m_rect.getSize().y });
    updateSize();
}

void sfui::TextBox::setSizeY(float size_y) {
    m_rect.setSize({ m_rect.getSize().x, size_y });
    updateSize();
}

void sfui::TextBox::setBackgroundColor(sf::Color color) {
    m_rect.setFillColor(color);
}

void sfui::TextBox::setOutlineThickness(float thickness) {
    m_rect.setOutlineThickness(thickness);
}

void sfui::TextBox::setOutlineColor(sf::Color color) {
    m_rect.setOutlineColor(color);
}

sf::Vector2f sfui::TextBox::getPosition() {
    return m_rect.getPosition();
}

sf::Vector2f sfui::TextBox::getSize() {
    return m_rect.getSize();
}

std::string sfui::TextBox::getText() {
    return input_string_;
}

void sfui::TextBox::centrateText() {
    m_place_holder->setOrigin(m_place_holder->getGlobalBounds().size / 2.f + m_place_holder->getLocalBounds().position);
    m_place_holder->setPosition({ m_rect.getPosition().x + m_place_holder->getLocalBounds().size.x / 2.f + 5, m_rect.getPosition().y + (m_rect.getSize().y / 2.f) });
    m_text->setOrigin(m_place_holder->getOrigin());
    m_text->setPosition(m_place_holder->getPosition());
}

void sfui::TextBox::updateSize() {
    m_rect.setSize({ m_rect.getSize().x, static_cast<float>(m_place_holder->getCharacterSize()) });
    m_text->setCharacterSize(m_place_holder->getCharacterSize());
}

bool sfui::TextBox::isMouseOver(sf::Vector2f mouse_position) {
    return m_rect.getGlobalBounds().contains(mouse_position);
}