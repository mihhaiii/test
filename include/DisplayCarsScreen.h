#ifndef DISPLAYCARSSCREEN_H
#define DISPLAYCARSSCREEN_H

#include <bits/stdc++.h>
#include "SFML/Graphics.hpp"

#include "Masina.h"
#include "MasinaManager.h"
#include "Screen.h"
#include "Button.h"
#include "utils.h"
#include "Label.h"
#include "CheckBox.h"
#include "CheckBoxManager.h"

using namespace std;

class DisplayCarsScreen
{
    public:
        DisplayCarsScreen();
        virtual ~DisplayCarsScreen();

        ButtonAction Show(sf::RenderWindow&,MasinaManager*);

    protected:

    private:
        sf::Texture _texture;
        sf::Sprite _sprite;

        Button leftButtonObj, rightButtonObj, detailsButtonObj, backButtonObj;
        vector<CheckBox*> boxes;
};

#endif // DISPLAYCARSSCREEN_H
