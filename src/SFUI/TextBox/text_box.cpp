#include "../../../include/SFUI/TextBox/text_box.hpp"

void sfui::TextBox::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    if (m_is_hidden) return;
    target.draw(m_rect, states);
    if (m_place_holder != nullptr && (m_draw_place_holder && m_input_string.empty())) target.draw(*m_place_holder, states);
    if (m_text != nullptr) target.draw(*m_text, states);
}

void sfui::TextBox::update(const sf::RenderWindow& window) {
    centrateText();
}

void sfui::TextBox::processEvents(const sf::Event& event) {
    if (!m_is_enabled || m_is_hidden) return;
    if (const sf::Event::MouseButtonPressed* btn_pressed = event.getIf<sf::Event::MouseButtonPressed>()) {
        m_is_active = sfui::isMouseOver(m_rect, static_cast<sf::Vector2f>(btn_pressed->position));
        m_draw_place_holder = (m_input_string.empty() && !m_is_active);
    }

    if (const sf::Event::KeyPressed* key = event.getIf<sf::Event::KeyPressed>())
        if (key->scancode == sf::Keyboard::Scancode::Enter)
            m_is_active = false;

    if (const sf::Event::TextEntered* m_text_entered = event.getIf<sf::Event::TextEntered>()) {
        if (m_is_active && (static_cast<int>(m_text_entered->unicode) < 128)) {
            if (static_cast<int>(m_text_entered->unicode) == BAKSPACE_KEY) {
                if (!m_input_string.empty()) {
                    m_input_string.pop_back();
                    m_text->setText(m_input_string);
                }
            } else {
                if (m_text->getSize().x < m_rect.getGlobalBounds().size.x - m_glyph_size * 2.f) {
                    m_input_string += static_cast<char>(m_text_entered->unicode);
                    m_text->setText(m_input_string);
                }
            }
            if (!m_input_string.empty()) m_draw_place_holder = false;
            else m_draw_place_holder = true;
        }
    }
}

void sfui::TextBox::setEnabled(bool enabled) { m_is_enabled = enabled; }
void sfui::TextBox::hide(bool hidden) { m_is_hidden = hidden; }
void sfui::TextBox::setTextColor(sf::Color color) { m_text->setFillColor(color); }
void sfui::TextBox::setPlaceHolderText(const std::string& text) { m_place_holder->setText(text); }
void sfui::TextBox::setText(const std::string& text) {
    m_input_string = text;
    m_text->setText(m_input_string);
}
void sfui::TextBox::setTextSize(float size) {
    m_text->setCharacterSize(size);
    if (m_place_holder != nullptr) m_place_holder->setCharacterSize(size);
    m_rect.setSize({ m_rect.getSize().x, static_cast<float>(m_text->getCharacterSize()) });
}
void sfui::TextBox::setPosition(sf::Vector2f position) { m_rect.setPosition(position); }
void sfui::TextBox::setPositionX(float position_x) { m_rect.setPosition({ position_x, m_rect.getPosition().y }); }
void sfui::TextBox::setPositionY(float position_y) { m_rect.setPosition({ m_rect.getPosition().x, position_y }); }
void sfui::TextBox::setSize(sf::Vector2f size) { m_rect.setSize(size); }
void sfui::TextBox::setSizeX(float size_x) { m_rect.setSize({ size_x, m_rect.getSize().y }); }
void sfui::TextBox::setSizeY(float size_y) { m_rect.setSize({ m_rect.getSize().x, size_y }); }
void sfui::TextBox::setBackgroundColor(sf::Color color) { m_rect.setFillColor(color); }
void sfui::TextBox::setOutlineThickness(float thickness) { m_rect.setOutlineThickness(thickness); }
void sfui::TextBox::setOutlineColor(sf::Color color) { m_rect.setOutlineColor(color); }
void sfui::TextBox::centrateText() {
    m_text->setPosition({
        m_rect.getPosition().x,
        m_rect.getPosition().y + m_rect.getSize().y / 2.f - m_text->getCharacterSize() / 2.f
    });
    if (m_place_holder != nullptr) m_place_holder->setPosition(m_text->getPosition());
}
sf::Vector2f sfui::TextBox::getPosition() { return m_rect.getPosition(); }
sf::Vector2f sfui::TextBox::getSize() { return m_rect.getSize(); }
std::string sfui::TextBox::getText() { return m_input_string; }