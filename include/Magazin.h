#ifndef MAGAZIN_H
#define MAGAZIN_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "masina.h"
#include "SFML/Graphics.hpp"
#include "utils.h"
#include "SplashScreen.h"
#include "LogInfoScreen.h"
#include "LogScreen.h"
#include "RegisterScreen.h"
#include "Menu.h"
#include "Screen.h"
#include "UserManager.h"
#include "MasinaManager.h"
#include "DisplayCarsScreen.h"
#include "User.h"
#include "Button.h"
#include "Label.h"
#include "FormField.h"
#include "CarScreen.h"
#include "MyCartScreen.h"
#include "MasinaDeCurse.h"
#include "MasinaSport.h"
#include "SUV.h"
#include "Limuzina.h"
#include "MyCart.h"

using namespace std;

class Magazin
{
    public:
        Magazin();
        virtual ~Magazin();
        void startApp();

        void ShowMenu();
        void ShowSplash();
        void ShowLogInfo();
        void ShowLogScreen();
        void ShowRegisterScreen();
        void DisplayCars();
        void ShowCarScreen();
        void ShowMyCartScreen();

    protected:

    private:
        States _state;
        sf::RenderWindow _mainWindow;

        UserManager _userManager;
        MasinaManager _carManager;

        void appLoop();
};

#endif // MAGAZIN_H
