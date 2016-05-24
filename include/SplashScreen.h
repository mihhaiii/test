#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <bits/stdc++.h>
#include "SFML/Graphics.hpp"
using namespace std;
class SplashScreen
{
    public:
        SplashScreen();
        virtual ~SplashScreen();

        void show(sf::RenderWindow&);

    protected:

    private:
        sf::Sprite _sprite;
        sf::Texture _texture;
};

#endif // SPLASHSCREEN_H
