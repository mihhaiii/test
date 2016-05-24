#ifndef CHECKBOX_H
#define CHECKBOX_H

#include <bits/stdc++.h>
#include "SFML/Graphics.hpp"
#include "utils.h"
#include "Label.h"
using namespace std;

class CheckBox
{
    public:
        CheckBox();

        void setPosition(sf::Vector2f);
        sf::Vector2f getPosition();
        void setCheck(bool);
        bool getCheck();
        void setText(string);
        bool IsButtonPressedAt(int,int);

        void show(sf::RenderWindow&);

    protected:

    private:
        sf::RectangleShape box;
        sf::Texture texture;
        sf::Sprite sprite;
        Label text;

        bool isChecked;
};

#endif // CHECKBOX_H
