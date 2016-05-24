#ifndef REGISTERSCREEN_H
#define REGISTERSCREEN_H

#include <bits/stdc++.h>
#include "SFML/Graphics.hpp"
#include "Button.h"
#include "utils.h"
#include "Label.h"
#include "FormField.h"
#include "UserManager.h"
#include "Checker.h"

using namespace std;

class RegisterScreen
{
    public:
        RegisterScreen();
        virtual ~RegisterScreen();

        ButtonAction Show(sf::RenderWindow&, UserManager*);
        void DrawAll(sf::RenderWindow&);
        void ShowSuccess(sf::RenderWindow&);

    protected:

    private:
        sf::Texture _texture;
        sf::Sprite _sprite;

        Label registerLabelObj, nameLabelObj, usernameLabelObj, passwordLabelObj, emailLabelObj, congratsLabelObj, pressKeyLabelObj, warningLabelObj;

        Button registerButtonObj, backButtonObj;

        FormField nameFormObj, usernameFormObj, passwordFormObj, emailFormObj;
        void SetActive(FormField*);
};

#endif // REGISTERSCREEN_H
