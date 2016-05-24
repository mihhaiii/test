#ifndef CARSCREEN_H
#define CARSCREEN_H

#include <bits/stdc++.h>
#include "SFML/Graphics.hpp"
#include "utils.h"
#include "Masina.h"
#include "MasinaManager.h"
#include "Button.h"
#include "Label.h"
#include "User.h"

using namespace std;

class CarScreen
{
    public:
        CarScreen();
        virtual ~CarScreen();

        ButtonAction Show(sf::RenderWindow&, Masina*, User*);
        void DrawAll(sf::RenderWindow&, Masina*);

    protected:

    private:
        sf::Sprite _sprite;
        sf::Texture _texture;

        Button backButtonObj;
        Button buyCarButtonObj;
};

#endif // CARSCREEN_H
