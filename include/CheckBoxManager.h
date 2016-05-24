#ifndef CHECKBOXMANAGER_H
#define CHECKBOXMANAGER_H

#include <bits/stdc++.h>
#include "SFML/Graphics.hpp"
#include "utils.h"
#include "CheckBox.h"
using namespace std;
class CheckBoxManager
{
    public:
        CheckBoxManager();
        virtual ~CheckBoxManager();

        void addBox(CheckBox*);
        void drawAll(sf::RenderWindow&);
        void checkBoxAtPos(int);

    protected:

    private:

        vector<CheckBox*> checkBoxes;
};

#endif // CHECKBOXMANAGER_H
