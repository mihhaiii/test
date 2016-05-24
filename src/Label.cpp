#include "Label.h"

Label::Label()
{
    //ctor
    font.loadFromFile("arial.ttf");
    _str = "";
    text.setString(_str);
    text.setCharacterSize(12);
    text.setFont(font);
    text.setStyle(sf::Text::Italic);
    text.setColor(sf::Color::Black);

    _visible = true;
}

Label::~Label()
{
    //dtor
}

void Label::SetVisible(bool f) {
    _visible = f;
}

void Label::SetColor(string c) {
    if (c=="black") text.setColor(sf::Color::Black);
    if (c=="red") text.setColor(sf::Color::Red);
    if (c=="blue") text.setColor(sf::Color::Blue);
    if (c=="green") text.setColor(sf::Color::Green);
    if (c=="yellow") text.setColor(sf::Color::Yellow);
}

void Label::SetText(string x) {
    _str = x;
    text.setString(_str);
}
string Label::GetText() {
    //if (_str[_str.size()-1] == '|') return _str.substr(0,_str.size()-1);
    return _str;
}


void Label::SetPosition(int x, int y) {
    text.setPosition(sf::Vector2f(x,y));
}


void Label::SetPositionX(int x) {
    text.setPosition(sf::Vector2f(x,text.getPosition().y));
}


void Label::SetPositionY(int y) {
    text.setPosition(sf::Vector2f(text.getPosition().x,y));
}


void Label::SetCharacterSize(int sz)  {
    text.setCharacterSize(sz);
}
void Label::SetStyle(string st) {
   if (st == "italic") text.setStyle(sf::Text::Italic);
   if (st == "bold") text.setStyle(sf::Text::Bold);
   if (st == "underlined") text.setStyle(sf::Text::Underlined);
   if (st == "normal") text.setStyle(sf::Text::Regular);
}

void Label::AddLetter(char c) {
    _str += c;
    text.setString(_str);
}
void Label::PopLetter() {
    if (_str.size() != 0) {
        _str = _str.substr(0,_str.size()-1);
        text.setString(_str);
    }
}

int Label::GetWidth() {
    return text.getLocalBounds().width;
}
sf::Vector2f Label::getPosition() {
    return text.getPosition();
}

void Label::Show(sf::RenderWindow& window) {
   if (_visible)
        window.draw(text);
}

bool Label::isVisible() {
    return _visible;
}
