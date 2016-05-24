#include "RegisterScreen.h"

RegisterScreen::RegisterScreen()
: registerButtonObj("images/registerbutton1.png"),
  backButtonObj("images/backbutton.png")
{
    //ctor
    _texture.loadFromFile("images/background.png");
    _sprite.setTexture(_texture);


    nameFormObj.SetPosition(300,300);
    usernameFormObj.SetPosition(300,330);
    passwordFormObj.SetPosition(300,360);
    emailFormObj.SetPosition(300,390);
    registerButtonObj.SetPosition(300,420);
    backButtonObj.SetPosition(10,540);
    passwordFormObj.SetPasswordType(true);

    registerLabelObj.SetText("Înregistrare");
    registerLabelObj.SetStyle("italic");
    registerLabelObj.SetCharacterSize(30);
    registerLabelObj.SetPosition(50,50);

    nameLabelObj.SetText("Nume:");
    usernameLabelObj.SetText("Username:");
    passwordLabelObj.SetText("Parola:");
    emailLabelObj.SetText("Email:");

    nameLabelObj.SetPosition(150,300);
    usernameLabelObj.SetPosition(150,330);
    passwordLabelObj.SetPosition(150,360);
    emailLabelObj.SetPosition(150,390);

    warningLabelObj.SetText("Date incomplete sau incorecte");
    warningLabelObj.SetCharacterSize(30);
    warningLabelObj.SetColor("red");
    warningLabelObj.SetPosition(300, 500);
    warningLabelObj.SetVisible(false);

    congratsLabelObj.SetPosition(300,300);
    congratsLabelObj.SetText("Înregistrare reusita!");
    congratsLabelObj.SetCharacterSize(24);
    congratsLabelObj.SetColor("green");

    pressKeyLabelObj.SetPosition(300,400);
    pressKeyLabelObj.SetStyle("italic");
    pressKeyLabelObj.SetCharacterSize(12);
    pressKeyLabelObj.SetText("Apasati orice tasta pentru continuare...");

}

RegisterScreen::~RegisterScreen()
{
    //dtor
}
void RegisterScreen::DrawAll(sf::RenderWindow& window) {
    window.draw(_sprite);
    registerLabelObj.Show(window);
    passwordLabelObj.Show(window);
    usernameLabelObj.Show(window);
    emailLabelObj.Show(window);
    nameLabelObj.Show(window);
    warningLabelObj.Show(window);

    nameFormObj.Show(window);
    usernameFormObj.Show(window);
    passwordFormObj.Show(window);
    emailFormObj.Show(window);

    registerButtonObj.Show(window);
    backButtonObj.Show(window);
}


ButtonAction RegisterScreen::Show(sf::RenderWindow& window, UserManager* userManager) {
    window.clear();
    DrawAll(window);
    window.display();


    sf::Event event;
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
                   {
                        int x = event.mouseButton.x, y = event.mouseButton.y;
                        if (nameFormObj.IsButtonPressedAt(x,y)) SetActive(&nameFormObj);
                        else if (usernameFormObj.IsButtonPressedAt(x,y)) SetActive(&usernameFormObj);
                        else if (passwordFormObj.IsButtonPressedAt(x,y)) SetActive(&passwordFormObj);
                        else if (emailFormObj.IsButtonPressedAt(x,y)) SetActive(&emailFormObj);
                        else SetActive(NULL);

                        if (registerButtonObj.IsButtonPressedAt(x,y)) {
                            // verifica corectitudinea datelor
                            if (Checker::CheckRegister(nameFormObj.GetText(),usernameFormObj.GetText(),passwordFormObj.GetText(),emailFormObj.GetText(),userManager))
                                return ShowSuccess(window), userManager->AddUser(new User(nameFormObj.GetText(),usernameFormObj.GetText(),passwordFormObj.GetText())), ShowMenuAction;
                            else warningLabelObj.SetVisible(true);
                        }
                        if (backButtonObj.IsButtonPressedAt(x,y)) {
                            return BackAction;
                        }
                        break;
                   }
                case sf::Event::TextEntered:
                    if (event.text.unicode == 8) {
                        if (nameFormObj.IsActive()) nameFormObj.PopLetter();
                        if (usernameFormObj.IsActive()) usernameFormObj.PopLetter();
                        if (passwordFormObj.IsActive()) passwordFormObj.PopLetter();
                        if (emailFormObj.IsActive()) emailFormObj.PopLetter();
                    }
                    else if (event.text.unicode == 9) {
                        if (nameFormObj.IsActive()) SetActive(&usernameFormObj);
                        else if (usernameFormObj.IsActive()) SetActive(&passwordFormObj);
                        else if (passwordFormObj.IsActive()) SetActive(&emailFormObj);
                    }
                    else if (event.text.unicode == 13) {
                        if (Checker::CheckRegister(nameFormObj.GetText(),usernameFormObj.GetText(),passwordFormObj.GetText(),emailFormObj.GetText(),userManager))
                                return ShowSuccess(window), userManager->AddUser(new User(nameFormObj.GetText(),usernameFormObj.GetText(),passwordFormObj.GetText())), ShowMenuAction;
                        else warningLabelObj.SetVisible(true);
                    }
                    else {
                        char ch = (char)event.text.unicode;
                        if (nameFormObj.IsActive()) nameFormObj.AddLetter(ch);
                        else if (usernameFormObj.IsActive()) usernameFormObj.AddLetter(ch);
                        else if (passwordFormObj.IsActive()) passwordFormObj.AddLetter(ch);
                        else if (emailFormObj.IsActive()) emailFormObj.AddLetter(ch);
                    }
                    break;
            }
        }

        window.clear();
        DrawAll(window);
        window.display();
    }

}


void RegisterScreen::ShowSuccess(sf::RenderWindow& window) {
    window.clear();
    window.draw(_sprite);
    registerLabelObj.Show(window);
    congratsLabelObj.Show(window);
    pressKeyLabelObj.Show(window);

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
                break;
            case sf::Event::KeyPressed:
            case sf::Event::MouseButtonPressed:
                return;
            }
        }
    }
}

void RegisterScreen::SetActive(FormField* l) {
    nameFormObj.SetActive(false);
    usernameFormObj.SetActive(false);
    passwordFormObj.SetActive(false);
    emailFormObj.SetActive(false);
    if (l!=NULL) l->SetActive(true);
}
