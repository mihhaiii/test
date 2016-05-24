#ifndef UTILS_H
#define UTILS_H
#include <string>
#include "SFML/Graphics.hpp"
using namespace std;
enum Brands {
    FIAT, BMW, FORD, DACIA, AUDI, TOYOTA, FERARRI, VOLKSWAGEN, MERCEDES, OPEL
};

enum Models {
    a32, f5, h1100, j3r3, lk90, xb44, hu35, ui100,xb330, hwt4500
};

enum ButtonAction {
    ShowNextCarAction, ShowPrevCarAction, BackAction, ExitAction, ShowCarsAction, ViewCarAction, ShowMenuAction, ShowSplashAction,
    ShowWarningWindowAction, NothingAction, ShowLogSreenAction, ShowRegisterScreenAction, ShowLogInfoAction, ShowDetailsAction, ShowCarScreenAction,
    ShowMyCartAction, BuyCarAction,  DeleteFromCartAction
};

enum CarState {
InVanzare, Epuizat
};

enum Fuel
{
    Gasoline,
    Diesel
};

extern const string CarState2Str[];

extern const string CarFiles[];

extern const char* Brands2Str[];
extern const char* Models2Str[];

extern string int2str(int x);
extern void showText(string str, sf::RenderWindow& window, int x, int y);

enum States {
    uninitialized, showingSplashState, showingMenuState, showingLogInfoState, loggingState, registeringState, displayingCarsState, exitingState,
    showingCarScreenState, showingMyCartState
};

#endif // UTILS_H
