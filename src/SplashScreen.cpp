#include "SplashScreen.h"

SplashScreen::SplashScreen()
{
    //ctor
    _texture.loadFromFile("images/splash.jpg");
    _sprite.setTexture(_texture);
}

SplashScreen::~SplashScreen()
{
    //dtor
}

void SplashScreen::show(sf::RenderWindow& window) {
    window.clear();
    window.draw(_sprite);
    window.display();

    sf::Event event;
    while (1)
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed || event.type == sf::Event::MouseButtonPressed)
                return;
            if (event.type == sf::Event::Closed) {
                window.close();
                return;
            }
        }
    }
}
