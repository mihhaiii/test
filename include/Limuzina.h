#ifndef LIMUZINA_H
#define LIMUZINA_H

#include <bits/stdc++.h>
#include "SFML/Graphics.hpp"
#include "utils.h"
#include "Masina.h"

using namespace std;

class Limuzina : public Masina
{
    public:
        Limuzina();
        Limuzina(Brands,Models,int,int);
        virtual ~Limuzina();

        virtual void showImage(sf::RenderWindow&);
        virtual void showInfo(sf::RenderWindow&);
        virtual string toName();

        virtual void ShowDetail(sf::RenderWindow&);

    protected:

    private:
        int passangerCapacity;
        float length;
};

#endif // LIMUZINA_H
