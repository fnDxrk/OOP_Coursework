#include "../include/TextGame.hpp"

TextGame::TextGame(Font& font) {
    text.setFont(font);
    text.setCharacterSize(36);
    text.setColor(Color::White);
    text.setPosition(60, 30);
}

// FloatRect TextGame::getLocalBounds() {
//     return text.getLocalBounds();
// }

// void TextGame::setOrigin(float x, float y) {
//     text.setOrigin(x, y);
// }

void TextGame::setPosition(float x, float y) {
    text.setPosition(Vector2f(x, y));
}

void TextGame::setCharacterSize(int size) {
    text.setCharacterSize(size);
}

void TextGame::draw(RenderWindow* window, int score) {
    text.setString("Score : " + std::to_string(score));
    window->draw(text);
}

