#include "CheckBox.h"

CheckBox::CheckBox(){
    texture.loadFromFile("images/check.png");
    sprite.setTexture(texture);

    box.setFillColor(sf::Color::White);
    box.setSize(sf::Vector2f(30,30));
    box.setOutlineThickness(3);
    box.setOutlineColor(sf::Color::Black);

    text.SetCharacterSize(14);
    text.SetStyle("normal");
    text.SetColor("blue");

    isChecked = false;
}

void CheckBox::setPosition(sf::Vector2f v) {
    sprite.setPosition(v);
    box.setPosition(v);
    text.SetPosition((int)v.x+35,(int)v.y);
}
void CheckBox::setText(string s) {
    text.SetText(s);
}

sf::Vector2f CheckBox::getPosition() {
    return box.getPosition();
}

void CheckBox::setCheck(bool f) {
    isChecked = f;
}
bool CheckBox::getCheck() {
    return  isChecked;
}

void CheckBox::show(sf::RenderWindow& window) {
    window.draw(box);
    if (isChecked) window.draw(sprite);
    text.Show(window);
}


bool CheckBox::IsButtonPressedAt(int x, int y){
    return x >= box.getGlobalBounds().left && x <= box.getGlobalBounds().left + box.getGlobalBounds().width &&
    y >= box.getGlobalBounds().top && y <= box.getGlobalBounds().top + box.getGlobalBounds().height;
}

