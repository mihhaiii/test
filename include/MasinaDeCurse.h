#ifndef MASINADECURSE_H
#define MASINADECURSE_H

#include <bits/stdc++.h>
#include "SFML/Graphics.hpp"
#include "utils.h"
#include "Masina.h"

using namespace std;

class MasinaDeCurse : public Masina
{
    public:
        MasinaDeCurse();
        MasinaDeCurse(Brands,Models,int,int);
        virtual ~MasinaDeCurse();

        virtual void showImage(sf::RenderWindow&);
        virtual void showInfo(sf::RenderWindow&);
        virtual string toName();

        virtual void ShowDetail(sf::RenderWindow&);

    protected:
        int horsePower;
        float acceleration;

    private:
};

#endif // MASINADECURSE_H
