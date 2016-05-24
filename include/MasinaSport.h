#ifndef MASINA_SPORT_H
#define MASINA_SPORT_H

#include <bits/stdc++.h>
#include "SFML/Graphics.hpp"
#include "utils.h"
#include "Masina.h"

using namespace std;

class MasinaSport : public Masina
{
    public:
        MasinaSport();
        MasinaSport(Brands,Models,int,int);
        virtual ~MasinaSport();


        virtual void showImage(sf::RenderWindow&);
        virtual void showInfo(sf::RenderWindow&);
        virtual string toName();

        virtual void ShowDetail(sf::RenderWindow&);

    protected:

    private:
        int torque;
};

#endif // MASINA_SPORT_H
