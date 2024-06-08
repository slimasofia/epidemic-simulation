#ifndef TEXTMANAGER_H
#define TEXTMANAGER_H

#include <SFML/Graphics.hpp>
#include <string>
#include <map>

class TextManager {
public:
    TextManager();
    bool loadFont(const std::string& fontPath);
    void addText(const std::string& key, const std::string& text, int size, const sf::Color& color, float x, float y);
    void setText(const std::string& key, const std::string& text);
    void draw(sf::RenderWindow& window);

private:
    sf::Font font;
    std::map<std::string, sf::Text> texts;
};

#endif
