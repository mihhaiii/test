#include "Menu.h"

Menu::Menu() :
    carListButtonObj("images/listamasinibutton.png"),
    exitButtonObj("images/iesirebutton.png"),
    myCartButtonObj("images/cosulmeubutton.png"),
    logOutButtonObj("images/logoutbutton.png")
{
    //ctor
    _texture.loadFromFile("images/meniu.png");
    _sprite.setTexture(_texture);

    carListButtonObj.SetPosition(300,70);
    myCartButtonObj.SetPosition(300,105);
    logOutButtonObj.SetPosition(300,140);
    exitButtonObj.SetPosition(300,175);

    carListButtonObj.SetAction(ShowCarsAction);
    myCartButtonObj.SetAction(ShowMyCartAction);
    logOutButtonObj.SetAction(ShowLogInfoAction);
    exitButtonObj.SetAction(ExitAction);

    menu.SetPosition(370,40);
    menu.SetText("Meniu");
    menu.SetCharacterSize(24);
    menu.SetStyle("normal");
}

Menu::~Menu()
{
    //dtor
}

ButtonAction Menu::Show(sf::RenderWindow& window)
{
    window.clear();
    window.draw(_sprite);
    carListButtonObj.Show(window);
    myCartButtonObj.Show(window);
    logOutButtonObj.Show(window);
    exitButtonObj.Show(window);
    menu.Show(window);
    window.display();

    vector<Button*> buttons;
    buttons.push_back(&carListButtonObj);
    buttons.push_back(&exitButtonObj);
    buttons.push_back(&logOutButtonObj);
    buttons.push_back(&myCartButtonObj);

    sf::Event event;
    while (1)
    {
        while (window.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    return NothingAction;
                    break;
                case sf::Event::MouseButtonPressed:
                    {
                        int x=event.mouseButton.x, y=event.mouseButton.y;
                        for(auto button : buttons) {
                            if (button->IsButtonPressedAt(x,y)) {
                                if (button->GetAction() != NothingAction) {
                                    return button->GetAction();
                                }
                            }
                        }
                    }
            }
        }
    }
}

