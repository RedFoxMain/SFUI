#include "../../../include/SFUI/TextBox/text_box.hpp"

void sfui::TextBox::processEvents(const sf::Event& event) {
    if (const sf::Event::MouseButtonPressed* btn_pressed = event.getIf<sf::Event::MouseButtonPressed>()) {
        is_active_ = isMouseOver(static_cast<sf::Vector2f>(btn_pressed->position));
        draw_place_holder_ = (text->getString().isEmpty() && !is_active_);
    }

    if (const sf::Event::KeyPressed* key = event.getIf<sf::Event::KeyPressed>())
        if (key->scancode == sf::Keyboard::Scancode::Enter)
            is_active_ = false;

    if (const sf::Event::TextEntered* text_entered = event.getIf<sf::Event::TextEntered>()) {
        if (is_active_ && (static_cast<int>(text_entered->unicode) < 128)) {
            if ((static_cast<int>(text_entered->unicode) == BAKSPACE_KEY) || (m_rect.getGlobalBounds().size.x > text->getGlobalBounds().size.x + text->getCharacterSize())) { // Limit for text
                if (static_cast<int>(text_entered->unicode) == BAKSPACE_KEY) {
                    if (!input_string_.empty()) { input_string_.pop_back(); }
                }  else input_string_ += static_cast<char>(text_entered->unicode);
                text->setString(input_string_);
                if (!text->getString().isEmpty()) draw_place_holder_ = false;
                else draw_place_holder_ = true;
            } 
        }
    }
}

void sfui::TextBox::draw(sf::RenderWindow* wnd) {
    wnd->draw(m_rect);
    if (place_holder && draw_place_holder_) place_holder->draw(wnd);
    if (text) text->draw(wnd);
    updateSize();
    // centrateText();
}

void sfui::TextBox::setPosition(sf::Vector2f position) {
    m_rect.setPosition(position);
    centrateText();
}

void sfui::TextBox::setPositionX(float position_x) {
    m_rect.setPosition({ position_x, m_rect.getPosition().y });
}

void sfui::TextBox::setPositionY(float position_y) {
    m_rect.setPosition({ m_rect.getPosition().x, position_y });
}

void sfui::TextBox::setSize(sf::Vector2f size) {
    m_rect.setSize(size);
}

void sfui::TextBox::setSizeX(float size_x) {
    m_rect.setSize({ size_x, m_rect.getSize().y });
}

void sfui::TextBox::setSizeY(float size_y) {
    m_rect.setSize({ m_rect.getSize().x, size_y });
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

sf::Angle sfui::TextBox::getRotation() {
    return m_rect.getRotation();
}

void sfui::TextBox::centrateText() {
    place_holder->setOrigin(place_holder->getGlobalBounds().size / 2.f + place_holder->getLocalBounds().position);
    place_holder->setPosition({ m_rect.getPosition().x + place_holder->getLocalBounds().size.x / 2.f + 5, m_rect.getPosition().y + (m_rect.getSize().y / 2.f) });
    text->setOrigin(place_holder->getOrigin());
    text->setPosition(place_holder->getPosition());
}

void sfui::TextBox::updateSize() {
    m_rect.setSize({ m_rect.getSize().x, static_cast<float>(place_holder->getCharacterSize()) });
    text->setCharacterSize(place_holder->getCharacterSize());
}

bool sfui::TextBox::isMouseOver(sf::Vector2f mouse_position) {
    return m_rect.getGlobalBounds().contains(mouse_position);
}