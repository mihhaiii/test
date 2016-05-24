#include "LogInfoScreen.h"

LogInfoScreen::LogInfoScreen()
{
    //ctor
    _texture.loadFromFile("images/loginfo.png");
    _sprite.setTexture(_texture);

}

LogInfoScreen::~LogInfoScreen()
{
    //dtor
}
ButtonAction LogInfoScreen::Show(sf::RenderWindow& window)
{
    Button logInButtonObj("images/loginbutton.png");
    logInButtonObj.SetPosition(264,245);
    logInButtonObj.SetAction(ShowLogSreenAction);

    Button registerButtonObj("images/registerbutton.png");
    registerButtonObj.SetPosition(264, 291);
    registerButtonObj.SetAction(ShowRegisterScreenAction);

    buttons.push_back(logInButtonObj);
    buttons.push_back(registerButtonObj);

    window.clear();
    window.draw(_sprite);
    for (auto button : buttons)
        button.Show(window);

    window.display();

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
                for(auto button : buttons)
                    if (button.IsButtonPressedAt((int)event.mouseButton.x, (int)event.mouseButton.y))
                        if (button.GetAction() != NothingAction)
                            return button.GetAction();
            }
        }
    }
}

