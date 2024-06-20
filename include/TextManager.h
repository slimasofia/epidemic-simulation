#ifndef TEXTMANAGER_H
#define TEXTMANAGER_H

#include <SFML/Graphics.hpp>
#include <string>
#include <map>
using namespace std;

class TextManager {
public:
    TextManager();
    bool loadFont(const string& fontPath);
    void addText(const string& key, const string& text, int size, const sf::Color& color, float x, float y);
    void setText(const string& key, const string& text);
    void draw(sf::RenderWindow& window);

private:
    sf::Font font;
    std::map<string, sf::Text> texts;
};

#endif
