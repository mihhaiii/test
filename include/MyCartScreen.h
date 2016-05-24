#ifndef MYCARTSCREEN_H
#define MYCARTSCREEN_H

#include <bits/stdc++.h>
#include "SFML/Graphics.hpp"
#include "Masina.h"
#include "MasinaManager.h"
#include "Screen.h"
#include "Button.h"
#include "utils.h"
#include "Label.h"
#include "User.h"
#include "CheckBox.h"
#include "CheckBoxManager.h"

using namespace std;

class MyCartScreen
{
    public:
        MyCartScreen();

        ButtonAction Show(sf::RenderWindow&, User*);

    protected:

    private:
        sf::Texture _texture;
        sf::Sprite _sprite;

        Button backButtonObj, upButtonObj, downButtonObj;
        Label warningLabelObj;

        vector<CheckBox*> boxes;
};

#endif // MYCARTSCREEN_H
