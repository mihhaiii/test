#ifndef SUV_H
#define SUV_H

#include <bits/stdc++.h>
#include "SFML/Graphics.hpp"
#include "utils.h"
#include "Masina.h"

using namespace std;

class SUV : public Masina
{
    public:
        SUV();
        SUV(Brands,Models,int,int);
        virtual ~SUV();

        virtual void showImage(sf::RenderWindow&);
        virtual void showInfo(sf::RenderWindow&);
        virtual string toName();

        virtual void ShowDetail(sf::RenderWindow&);

    protected:

    private:
        float weight;
};

#endif // SUV_H
