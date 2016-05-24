#ifndef SCREEN_H
#define SCREEN_H

#include <bits/stdc++.h>
#include "SFML/Graphics.hpp"
using namespace std;
class Screen
{
   public:
        Screen();
        virtual ~Screen();


        void show(sf::RenderWindow&);

    protected:
        sf::Texture _texture;
        sf::Sprite _sprite;
    private:

};

#endif // SCREEN_H
