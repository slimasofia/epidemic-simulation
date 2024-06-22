#include "TextManager.h"

TextManager::TextManager() {}

bool TextManager::loadFont(const std::string& fontPath) {
    return font.loadFromFile(fontPath);
}

void TextManager::addText(const std::string& key, const std::string& text, int size, const sf::Color& color, float x, float y) {
    sf::Text sfText;
    sfText.setFont(font);
    sfText.setString(text);
    sfText.setCharacterSize(size);
    sfText.setFillColor(color);
    sfText.setPosition(x, y);
    texts[key] = sfText;
}

void TextManager::setText(const std::string& key, const std::string& text) {
    if (texts.find(key) != texts.end()) {
        texts[key].setString(text);
    }
}

void TextManager::draw(sf::RenderWindow& window) {
    for (const auto& pair : texts) {
        window.draw(pair.second);
    }
}

void TextManager::centerText(const std::string& key, const sf::RenderWindow& window) {
    if (texts.find(key) != texts.end()) {
        sf::Text& text = texts[key];
        sf::FloatRect textRect = text.getLocalBounds();
        text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
        text.setPosition(window.getSize().x / 2.0f, window.getSize().y / 2.0f);
    }
}