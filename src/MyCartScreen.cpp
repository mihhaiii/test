#include "MyCartScreen.h"

MyCartScreen::MyCartScreen() :
    backButtonObj("images/backbutton.png"),
    upButtonObj("images/upButton.png"),
    downButtonObj("images/downButton.png"),
    buyButton("images/cumparamasina.png"),
    deleteButton("images/scoatedincos.png")
{
    _texture.loadFromFile("images/background.png");
    _sprite.setTexture(_texture);

    backButtonObj.SetPosition(10,540);
    upButtonObj.SetPosition(300,30);
    downButtonObj.SetPosition(300,540);
    buyButton.SetPosition(550,100);
    deleteButton.SetPosition(550, 160);

    backButtonObj.SetAction(BackAction);
    upButtonObj.SetAction(ShowPrevCarAction);
    downButtonObj.SetAction(ShowNextCarAction);
    buyButton.SetAction(BuyCarAction);
    deleteButton.SetAction(DeleteFromCartAction);

    warningLabelObj.SetText("Nu exista masini de afisat");
    warningLabelObj.SetStyle("normal");
    warningLabelObj.SetCharacterSize(30);
    warningLabelObj.SetPosition(200,250);
    warningLabelObj.SetCharacterSize(12);
    warningLabelObj.SetVisible(false);
}


ButtonAction MyCartScreen::Show(sf::RenderWindow& window, User* user, MasinaManager* storeCars)
{
    MasinaManager* mm = user->getCarList();

    vector<Button*> buttons;
    buttons.push_back(&backButtonObj);
    buttons.push_back(&upButtonObj);
    buttons.push_back(&downButtonObj);
    buttons.push_back(&deleteButton);
    buttons.push_back(&buyButton);

    for(int i=0;i<5;i++)
       boxes.push_back(new CheckBox());
   for(int i=0;i<5;i++)
       boxes[i]->setPosition(sf::Vector2f(30,i*100+50));

   boxes[0]->setText("Toate");
   boxes[1]->setText("Limuzine");
   boxes[2]->setText("Masini\nsport");
   boxes[3]->setText("Masini\nde\ncurse");
   boxes[4]->setText("SUV");
   boxes[0]->setCheck(true);


   Masina *m = mm->GetCurrentCar();
    while(1)
    {
          sf::Event event;
          while (window.pollEvent(event))
          {
              switch(event.type)
              {
              case sf::Event::Closed:
                return ExitAction;
                break;
                case sf::Event::MouseButtonPressed:
                {
                    for(auto button:buttons)
                        if (button->IsButtonPressedAt(event.mouseButton.x,event.mouseButton.y))
                    {
                        if (button->GetAction() == BackAction) return BackAction;
                        if (button->GetAction() == ShowPrevCarAction)
                        {
                            if (boxes[0]->getCheck()) mm->MoveBackward();
                            if (boxes[1]->getCheck()) mm->movePrev_Limuzina();
                            if (boxes[2]->getCheck()) mm->movePrev_MasinaSport();
                            if (boxes[3]->getCheck()) mm->movePrev_MasinaDeCurse();
                            if (boxes[4]->getCheck()) mm->movePrev_SUV();
                        }
                        if (button->GetAction() == ShowNextCarAction)
                        {
                            if (boxes[0]->getCheck()) mm->MoveForward();
                            if (boxes[1]->getCheck()) mm->moveNext_Limuzina();
                            if (boxes[2]->getCheck()) mm->moveNext_MasinaSport();
                            if (boxes[3]->getCheck()) mm->moveNext_MasinaDeCurse();
                            if (boxes[4]->getCheck()) mm->moveNext_SUV();
                        }
                        if (button->GetAction() == BuyCarAction)
                        {

                            // sterg masina din magazin si din cos

                            if (m!=NULL)
                            {
                                 ShowSuccess(window);

                                mm->DeleteCar(mm->getCurrentCarIndex());
                                storeCars->DeleteCar(m);
                            }

                            return ShowMenuAction;

                        }
                        if (button->GetAction() == DeleteFromCartAction)
                        {
                            if (m!=NULL)
                            {
                                mm->DeleteCar(mm->getCurrentCarIndex());
                            }
                        }
                    }
                    for(int i=0;i<5;i++)
                        if (boxes[i]->IsButtonPressedAt(event.mouseButton.x,event.mouseButton.y))
                    {
                        for(int j=0;j<5;j++) boxes[j]->setCheck(false);
                        boxes[i]->setCheck(true);
                    }
                }
                break;
                case sf::Event::KeyPressed:
                    {
                        if (event.key.code == sf::Keyboard::Up)
                        {
                            if (boxes[0]->getCheck()) mm->MoveBackward();
                            if (boxes[1]->getCheck()) mm->movePrev_Limuzina();
                            if (boxes[2]->getCheck()) mm->movePrev_MasinaSport();
                            if (boxes[3]->getCheck()) mm->movePrev_MasinaDeCurse();
                            if (boxes[4]->getCheck()) mm->movePrev_SUV();
                        }
                        if (event.key.code == sf::Keyboard::Down)
                        {
                            if (boxes[0]->getCheck()) mm->MoveForward();
                            if (boxes[1]->getCheck()) mm->moveNext_Limuzina();
                            if (boxes[2]->getCheck()) mm->moveNext_MasinaSport();
                            if (boxes[3]->getCheck()) mm->moveNext_MasinaDeCurse();
                            if (boxes[4]->getCheck()) mm->moveNext_SUV();
                        }
                    }
                    break;
              }
          }

        window.clear();
        window.draw(_sprite);
        for(auto button:buttons) button->Show(window);
        for(auto box:boxes) box->show(window);

        warningLabelObj.SetVisible(false);
        m = mm->GetCurrentCar();
        for(int i=0;i<5;i++)
            if (boxes[i]->getCheck())
        {
            if (i==0) {
                if (mm->GetCarsCount()==0) warningLabelObj.SetVisible(true), m = NULL;
            }
            if (i==1) {
                if (!mm->areLimuzina()) warningLabelObj.SetVisible(true), m=NULL;
                    else if (m->toName() != "Limuzina") mm->moveNext_Limuzina();
            }
            if (i==2) {
                if (!mm->areMasinaSport()) warningLabelObj.SetVisible(true), m=NULL;
                    else if (m->toName() != "MasinaSport") mm->moveNext_MasinaSport();
            }
            if (i==3) {
                if (!mm->areMasinaDeCurse()) warningLabelObj.SetVisible(true), m=NULL;
                    else if (m->toName() != "MasinaDeCurse") mm->moveNext_MasinaDeCurse();
            }
            if (i==4) {
                if (!mm->areSUV()) warningLabelObj.SetVisible(true), m=NULL;
                    else if (m->toName() != "SUV") mm->moveNext_SUV();
            }
        }


        if (m!=NULL) {
            m->showImage(window);
            m->showInfo(window);
        }
        warningLabelObj.Show(window);

        window.display();


    }
    return BackAction;
}

void MyCartScreen::ShowSuccess(sf::RenderWindow& window)
{
    Label success;
    success.SetText("Achizitionare reusita!");
    success.SetStyle("normal");
    success.SetCharacterSize(24);
    success.SetColor("green");
    success.SetPosition(250,230);

    sf::Texture tex;
    tex.loadFromFile("images/success.jpg");
    sf::Sprite spr;
    spr.setTexture(tex);

    window.clear();
    window.draw(spr);
    success.Show(window);
    window.display();
    sf::Event event;
    while(1)
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::MouseButtonPressed || event.type == sf::Event::KeyPressed
                || event.type == sf::Event::Closed) return;
        }
    }
}


