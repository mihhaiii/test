#ifndef __MY_CART_H__
#define __MY_CART_H__

#include <vector>
#include "Masina.h"

class MyCart
{
public:
    MyCart();
    ~MyCart();

    void AddMasina(Masina* toAdd);
    int GetMyCarsCount();
    int GetCurrentCarIndex();
    Masina* GetCurrentCar();

    void NewIndex();
    void MoveForward();
    void MoveBackward();

    void MoveNext_MasinaSport();
    void MoveNext_Limuzina();
    void MoveNext_SUV();
    void MoveNext_MasinaDeCurse();

    void MovePrev_MasinaSport();
    void MovePrev_Limuzina();
    void MovePrev_SUV();
    void MovePrev_MasinaDeCurse();

    bool IsInCart_Limuzina();
    bool IsInCart_MasinaSport();
    bool IsInCart_MasinaDeCurse();
    bool IsInCart_SUV();




protected:

private:
    std::vector<Masina*> myCars;
    int currentCarIndex;
    //bool isTrue;

};

#endif // __MY_CART_H__
