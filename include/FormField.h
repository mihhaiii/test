#ifndef FORMFIELD_H
#define FORMFIELD_H

#include <bits/stdc++.h>
#include "SFML/Graphics.hpp"
#include "utils.h"
#include "Label.h"

using namespace std;

class FormField
{
    public:
        FormField();
        virtual ~FormField();

        void AddLetter(char);
        void PopLetter();
        void SetPosition(int, int);
        void Show(sf::RenderWindow&);
        bool IsButtonPressedAt(int, int);
        string GetText();
        void SetActive(bool);
        bool IsActive();
        void SetPasswordType(bool);

    protected:
        sf::RectangleShape shape;
        Label textLabelObj, encryptedLabel, cursor;
        bool _active, _passwordType;
        sf::Clock clock;

    private:
        void UpdateCursor();

};

#endif // FORMFIELD_H
