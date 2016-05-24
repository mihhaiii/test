#ifndef MASINAMANAGER_H
#define MASINAMANAGER_H

#include <bits/stdc++.h>
#include "SFML/Graphics.hpp"
#include "Masina.h"

using namespace std;

class MasinaManager
{
    public:
        MasinaManager();
        virtual ~MasinaManager();

        void AddCar(Masina*);
        void ShadowCar(int id);
        void ShadowCar(Masina*);
        void DeleteCar(int id);
        void DeleteCar(Masina*);

        Masina* GetCurrentCar();
        void MoveForward();
        void MoveBackward();

        void moveNext_MasinaSport();
        void moveNext_Limuzina();
        void moveNext_SUV();
        void moveNext_MasinaDeCurse();

        void movePrev_MasinaSport();
        void movePrev_Limuzina();
        void movePrev_SUV();
        void movePrev_MasinaDeCurse();
        int getCurrentCarIndex();
        int GetCarsCount();

        bool areLimuzina();
        bool areMasinaSport();
        bool areMasinaDeCurse();
        bool areSUV();

    protected:

    private:
        vector<Masina*> carList;

        int currentCarIndex;



};

#endif // MASINAMANAGER_H
