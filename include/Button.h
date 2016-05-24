#ifndef BUTTON_H
#define BUTTON_H

#include <bits/stdc++.h>
#include "SFML/Graphics.hpp"
#include "utils.h"

using namespace std;

class Button
{
    public:
        Button(string);
        virtual ~Button();

        bool IsButtonPressedAt(int,int);
        void Show(sf::RenderWindow&);
        void SetPosition(int,int);
        sf::Vector2i GetPosition();
        ButtonAction GetAction();
        void SetAction(ButtonAction);


    protected:

        sf::Rect<int> _rect;
        ButtonAction actionObj;

    private:
        sf::Sprite _sprite;
        sf::Texture _texture;
        string _filename;
};

#endif // BUTTON_H
