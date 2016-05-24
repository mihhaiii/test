#ifndef MENU_H
#define MENU_H

#include <bits/stdc++.h>
#include "SFML/Graphics.hpp"
#include "utils.h"
#include "Label.h"
#include "Button.h"

using namespace std;

class Menu
{
    public:
        Menu();
        virtual ~Menu();

        ButtonAction Show(sf::RenderWindow&);

    protected:

    private:
        sf::Texture _texture;
        sf::Sprite _sprite;

        Button carListButtonObj, exitButtonObj, myCartButtonObj, logOutButtonObj;
        Label menu;
};

#endif // MENU_H
