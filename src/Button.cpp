#include "Button.h"

Button::Button(string filename)
: _filename(filename)
{
    //ctor
    _texture.loadFromFile(_filename);
    _sprite.setTexture(_texture);

    _rect.left = 0;
    _rect.width = 0;
    _rect.top = 0;
    _rect.height = 0;
}

Button::~Button()
{
    //dtor
}

bool Button::IsButtonPressedAt(int x, int y){
    return x >= _rect.left && x <= _rect.left + _rect.width && y >= _rect.top && y <= _rect.top + _rect.height;
}

void Button::Show(sf::RenderWindow& window) {

    window.draw(_sprite);
}
void Button::SetPosition(int x, int y)
{
    _sprite.setPosition(x,y);
    _rect.left = x;
    _rect.top = y;
    _rect.width = _sprite.getLocalBounds().width;
    _rect.height = _sprite.getLocalBounds().height;
}

sf::Vector2i Button::GetPosition() {
    return sf::Vector2i(_rect.left, _rect.top);
}

ButtonAction Button::GetAction() {
    return actionObj;
}
void Button::SetAction(ButtonAction action) {
    actionObj = action;
}
