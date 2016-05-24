#ifndef LABEL_H
#define LABEL_H

#include <bits/stdc++.h>
#include "SFML/Graphics.hpp"
#include "utils.h"

using namespace std;

class Label
{
    public:
        Label();
        virtual ~Label();

        void Show(sf::RenderWindow&);
        void SetText(string);
        void SetPosition(int,int);
        void SetPositionX(int);
        void SetPositionY(int);
        void SetStyle(string);
        void SetCharacterSize(int);
        void PopLetter();
        void AddLetter(char);
        int GetWidth();
        string GetText();
        sf::Vector2f getPosition();
        void SetVisible(bool);
        bool isVisible();
        void SetColor(string);

    protected:
        string _str;
        sf::Text text;
        sf::Font font;
    private:
        bool _visible;
};

#endif // LABEL_H
