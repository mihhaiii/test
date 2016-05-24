#include "DisplayCarsScreen.h"

DisplayCarsScreen::DisplayCarsScreen() :
    leftButtonObj("images/leftbutton.png"),
    rightButtonObj("images/rightbutton.png"),
    detailsButtonObj("images/afisdetalii.png"),
    backButtonObj("images/backButton.png")
{
    _texture.loadFromFile("images/background1.png");
    _sprite.setTexture(_texture);

    leftButtonObj.SetPosition(50,300);
    rightButtonObj.SetPosition(720,300);
    detailsButtonObj.SetPosition(300,500);
    backButtonObj.SetPosition(10,540);

    leftButtonObj.SetAction(ShowPrevCarAction);
    rightButtonObj.SetAction(ShowNextCarAction);
    detailsButtonObj.SetAction(ShowCarScreenAction);
    backButtonObj.SetAction(BackAction);
}

DisplayCarsScreen::~DisplayCarsScreen()
{
    //dtor
}

ButtonAction DisplayCarsScreen::Show(sf::RenderWindow& window, MasinaManager* mm)
{
    int currentCarIndex = 0;
    int carsNumber = mm->GetCarsCount();



   vector<Button*> buttons;
   buttons.push_back(&leftButtonObj);
   buttons.push_back(&rightButtonObj);
   buttons.push_back(&detailsButtonObj);
   buttons.push_back(&backButtonObj);
   for(int i=0;i<5;i++)
   {
       boxes.push_back(new CheckBox());
   }
   for(int i=0;i<5;i++)
   {
       boxes[i]->setPosition(sf::Vector2f(i*150+20,120));
   }
   boxes[0]->setText("Toate");
   boxes[1]->setText("Limuzine");
   boxes[2]->setText("Masini\nsport");
   boxes[3]->setText("Masini\nde\ncurse");
   boxes[4]->setText("SUV");
   boxes[0]->setCheck(true);

    while (1)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Left)
                    {
                        if (boxes[0]->getCheck()) mm->MoveBackward();
                        if (boxes[1]->getCheck()) mm->movePrev_Limuzina();
                        if (boxes[2]->getCheck()) mm->movePrev_MasinaSport();
                        if (boxes[3]->getCheck()) mm->movePrev_MasinaDeCurse();
                        if (boxes[4]->getCheck()) mm->movePrev_SUV();
                    }
                if (event.key.code == sf::Keyboard::Right)
                   {
                        if (boxes[0]->getCheck()) mm->MoveForward();
                        if (boxes[1]->getCheck()) mm->moveNext_Limuzina();
                        if (boxes[2]->getCheck()) mm->moveNext_MasinaSport();
                        if (boxes[3]->getCheck()) mm->moveNext_MasinaDeCurse();
                        if (boxes[4]->getCheck()) mm->moveNext_SUV();
                   }

            }
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                for(auto button : buttons)
                {
                    if (button->IsButtonPressedAt(event.mouseButton.x,event.mouseButton.y))
                    {
                        if (button->GetAction() == ShowPrevCarAction)
                        {
                            if (boxes[0]->getCheck()) mm->MoveBackward();
                            if (boxes[1]->getCheck()) mm->movePrev_Limuzina();
                            if (boxes[2]->getCheck()) mm->movePrev_MasinaSport();
                            if (boxes[3]->getCheck()) mm->movePrev_MasinaDeCurse();
                            if (boxes[4]->getCheck()) mm->movePrev_SUV();
                        }
                        else if (button->GetAction() == ShowNextCarAction)
                        {
                            if (boxes[0]->getCheck()) mm->MoveForward();
                            if (boxes[1]->getCheck()) mm->moveNext_Limuzina();
                            if (boxes[2]->getCheck()) mm->moveNext_MasinaSport();
                            if (boxes[3]->getCheck()) mm->moveNext_MasinaDeCurse();
                            if (boxes[4]->getCheck()) mm->moveNext_SUV();
                        }
                        else
                            return button->GetAction();
                    }
                }
                for (int i=0;i<5;i++)
                {
                    if (boxes[i]->IsButtonPressedAt(event.mouseButton.x,event.mouseButton.y))
                    {
                        for(int j=0;j<5;j++)
                            boxes[j]->setCheck(false);
                        boxes[i]->setCheck(true);
                        if (i==1) mm->moveNext_Limuzina();
                        if (i==2) mm->moveNext_MasinaSport();
                        if (i==3) mm->moveNext_MasinaDeCurse();
                        if (i==4) mm->moveNext_SUV();
                    }
                }
            }
        }
        window.clear();
        window.draw(_sprite);
        mm->GetCurrentCar()->showImage(window);
        mm->GetCurrentCar()->showInfo(window);
        leftButtonObj.Show(window);
        rightButtonObj.Show(window);
        detailsButtonObj.Show(window);
        backButtonObj.Show(window);
        for(int i=0;i<5;i++)
        {
            boxes[i]->show(window);
        }

        showText(int2str(mm->getCurrentCarIndex()), window, 25,25);

        window.display();
    }
}
