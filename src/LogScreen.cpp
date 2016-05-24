#include "LogScreen.h"

LogScreen::LogScreen() :
     okButtonObj("images/okbutton.png"),
     backButtonObj("images/backbutton.png")
{
    _texture.loadFromFile("images/background.png");
    _sprite.setTexture(_texture);

    usernameFormObj.SetPosition(100,100);
    passwordFormObj.SetPosition(100,130);
    okButtonObj.SetPosition(100,160);
    backButtonObj.SetPosition(10,540);

    passwordFormObj.SetPasswordType(true);

    logInLabelObj.SetText("Logare");
    logInLabelObj.SetStyle("italic");
    logInLabelObj.SetCharacterSize(30);
    logInLabelObj.SetPosition(50,50);

    usernameLabelObj.SetText("Username:");
    usernameLabelObj.SetStyle("italic");
    usernameLabelObj.SetCharacterSize(12);
    usernameLabelObj.SetPosition(20,100);

    passwordLabelObj.SetText("Parola:");
    passwordLabelObj.SetStyle("italic");
    passwordLabelObj.SetCharacterSize(12);
    passwordLabelObj.SetPosition(20,130);

    warningLabelObj.SetText("Combinatia user-parola nu este recunoscuta");
    warningLabelObj.SetStyle("italic");
    warningLabelObj.SetColor("red");
    warningLabelObj.SetCharacterSize(30);
    warningLabelObj.SetPosition(150,450);
    warningLabelObj.SetVisible(false);
}

LogScreen::~LogScreen()
{
    //dtor
}

void LogScreen::DrawAll(sf::RenderWindow& window) {
     window.draw(_sprite);
     usernameFormObj.Show(window);
     passwordFormObj.Show(window);
     okButtonObj.Show(window);
     logInLabelObj.Show(window);
     usernameLabelObj.Show(window);
     passwordLabelObj.Show(window);
     warningLabelObj.Show(window);
     backButtonObj.Show(window);
}

ButtonAction LogScreen::Show(sf::RenderWindow& window, UserManager* userManager) {
    window.clear();
    DrawAll(window);
    window.display();

    sf::Event event;
    usernameFormObj.SetActive(true);
    while (1)
    {
        while (window.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::Closed:
                    return ExitAction;
                    break;

                case sf::Event::MouseButtonPressed:
                    if (usernameFormObj.IsButtonPressedAt(event.mouseButton.x,event.mouseButton.y))
                        usernameFormObj.SetActive(true), passwordFormObj.SetActive(false);

                    else if (passwordFormObj.IsButtonPressedAt(event.mouseButton.x,event.mouseButton.y))
                        usernameFormObj.SetActive(false), passwordFormObj.SetActive(true);

                    else
                        usernameFormObj.SetActive(false), passwordFormObj.SetActive(false);

                    if (okButtonObj.IsButtonPressedAt(event.mouseButton.x,event.mouseButton.y))
                    {
                        if (Checker::CheckLogIn(usernameFormObj.GetText(), passwordFormObj.GetText(), userManager))
                            {
                                User* user = userManager->UserToLogIn(usernameFormObj.GetText());
                                user->LogIn();
                                return ShowMenuAction;
                            }
                            else warningLabelObj.SetVisible(true);
                    }
                    else if (backButtonObj.IsButtonPressedAt(event.mouseButton.x,event.mouseButton.y))
                        return BackAction;
                    break;

                case sf::Event::TextEntered:
                    if (event.text.unicode == 13) {
                        if (Checker::CheckLogIn(usernameFormObj.GetText(), passwordFormObj.GetText(), userManager))
                        {
                            User* user = userManager->UserToLogIn(usernameFormObj.GetText());
                            user->LogIn();
                            return ShowMenuAction;
                        }
                        else warningLabelObj.SetVisible(true);
                    }
                    else if (event.text.unicode == 8) {
                        if (passwordFormObj.IsActive())
                            passwordFormObj.PopLetter();
                        else if (usernameFormObj.IsActive())
                            usernameFormObj.PopLetter();
                    }
                    else if (event.text.unicode == 9) {
                        if (usernameFormObj.IsActive()) {
                            usernameFormObj.SetActive(false);
                            passwordFormObj.SetActive(true);
                        }
                    }
                    else {
                        if (passwordFormObj.IsActive())
                            passwordFormObj.AddLetter((char)event.text.unicode);
                        else if (usernameFormObj.IsActive())
                            usernameFormObj.AddLetter((char)event.text.unicode);
                    }
                break;
            }
        }

        window.clear();
        DrawAll(window);
        window.display();

    }
}
