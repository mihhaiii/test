#include "Magazin.h"
#include "Masina.h"

#include <ctime>
#include <random>

Magazin::Magazin()
{
    srand(time(NULL));
    // incarc 10 masini random in _carList
    for (int i=0;i<10;i++)
    {
        Masina* m  = new Masina(Masina::getRandBrand(), Masina::getRandModel(), rand() % 1000 + 10000, rand()%60 + 1950);
        m->setImage(CarFiles[i]);
        _carManager.AddCar(m);
    }
    for (int i=10;i<17;i++)
    {
        Masina* m  = new MasinaDeCurse(Masina::getRandBrand(), Masina::getRandModel(), rand() % 1000 + 10000, rand()%60 + 1950);
        m->setImage(CarFiles[i]);
        _carManager.AddCar(m);
    }
    for (int i=17;i<21;i++)
    {
        Masina* m  = new Limuzina(Masina::getRandBrand(), Masina::getRandModel(), rand() % 1000 + 10000, rand()%60 + 1950);
        m->setImage(CarFiles[i]);
        _carManager.AddCar(m);
    }
    for (int i=21;i<28;i++)
    {
        Masina* m  = new MasinaSport(Masina::getRandBrand(), Masina::getRandModel(), rand() % 1000 + 10000, rand()%60 + 1950);
        m->setImage(CarFiles[i]);
        _carManager.AddCar(m);
    }
    for (int i=28;i<35;i++)
    {
        Masina* m  = new SUV(Masina::getRandBrand(), Masina::getRandModel(), rand() % 1000 + 10000, rand()%60 + 1950);
        m->setImage(CarFiles[i]);
        _carManager.AddCar(m);
    }


    _state = uninitialized;
    freopen("bazadedateuseri.txt","r",stdin);
    string a, b, c;
    while (cin>>a>>b>>c) {
        _userManager.AddUser(new User(a,b,c));
    }
}

Magazin::~Magazin()
{
    _userManager.WriteData("bazadedateuseri.txt");
}

void  Magazin::startApp()
{
    cout << "----------------Bine ati Venit!!!-----------------"<<endl;
    if (_state != uninitialized)
        return;

    _mainWindow.create(sf::VideoMode(800,600),"Magazin de masini");
    _state=showingSplashState;

    while (_mainWindow.isOpen())
    {
        appLoop();
    }
}

void Magazin::appLoop()
{
    switch(_state)
    {
    case exitingState:
        _mainWindow.close();
        break;
    case showingSplashState:
        ShowSplash();
        break;
    case showingMenuState:
        ShowMenu();
        break;
    case showingLogInfoState:
        ShowLogInfo();
        break;
    case loggingState:
        ShowLogScreen();
        break;
    case registeringState:
        ShowRegisterScreen();
        break;
    case displayingCarsState:
        DisplayCars();
        break;
    case showingCarScreenState:
        ShowCarScreen();
        break;
    case showingMyCartState:
        ShowMyCartScreen();
        break;
    }
}

void Magazin::ShowMenu()
{
    Menu m;
    ButtonAction res = m.Show(_mainWindow);
    switch(res)
    {
        case ShowCarsAction:
            _state = displayingCarsState;
            break;
        case ExitAction:
            _state = exitingState;
            break;
        case ShowLogInfoAction:
            _state = showingLogInfoState;
            break;
        case ShowMyCartAction:
            _state = showingMyCartState;
            break;
    }

}
void Magazin::ShowSplash()
{
    SplashScreen ss;
    ss.show(_mainWindow);
    _state=showingLogInfoState;
}

void Magazin::ShowLogInfo()
{
    LogInfoScreen lis;
    ButtonAction res = lis.Show(_mainWindow);
    switch(res)
    {
        case ShowLogSreenAction:
            _state = loggingState;
            break;
        case ShowRegisterScreenAction:
            _state = registeringState;
    }
}
void Magazin::ShowLogScreen()
{

    LogScreen ls;
    ButtonAction res = ls.Show(_mainWindow, &_userManager);

    switch(res)
    {
        case ShowMenuAction:
            _state = showingMenuState;
            break;
        case BackAction:
            _state = showingLogInfoState;
            break;
        case ExitAction:
            _state = exitingState;
    }
}

void Magazin::ShowRegisterScreen()
{
    RegisterScreen rs;
    ButtonAction res =  rs.Show(_mainWindow, &_userManager);
    switch(res)
    {
    case ShowMenuAction:
        _state = showingMenuState;
        break;
    case BackAction:
        _state = showingLogInfoState;
        break;
    case ExitAction:
        _state = exitingState;
    }
}

void Magazin::DisplayCars()
{
    DisplayCarsScreen dcs;

    ButtonAction res = dcs.Show(_mainWindow,&_carManager);
    switch(res)
    {
    case ShowCarScreenAction:
        _state = showingCarScreenState;
        break;
    case BackAction:
        _state = showingMenuState;
        break;
    case ExitAction:
        _state = exitingState;
    }
}

void Magazin::ShowCarScreen()
{
    CarScreen cs;
    ButtonAction res = cs.Show(_mainWindow, _carManager.GetCurrentCar(), _userManager.LoggedInUser());
    switch(res)
    {
    case BackAction:
        _state = displayingCarsState;
        break;
    case ExitAction:
        _state = exitingState;
        break;
    }
}

void Magazin::ShowMyCartScreen()
 {
    MyCartScreen mcs;
    ButtonAction res = mcs.Show(_mainWindow, _userManager.LoggedInUser(), &_carManager);
    switch(res)
    {

        case BackAction:
            _state = showingMenuState;
            break;
        case ExitAction:
            _state = exitingState;
            break;
    }
 }

