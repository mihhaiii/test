#include <iostream>
#include "MyCart.h"

using namespace std;

MyCart::MyCart()
{
    currentCarIndex = 0;
}

MyCart::~MyCart()
{
    for (auto it: myCars)
        delete it;
}

void MyCart::AddMasina(Masina* toAdd)
{
    myCars.push_back(toAdd);
    cout<<"Masina cumparata";
}

int MyCart::GetMyCarsCount()
{
    return myCars.size();
}

Masina* MyCart::GetCurrentCar() {
    if (myCars.size() == 0) return NULL;
    return myCars[currentCarIndex];
}

void MyCart::MoveForward() {
    currentCarIndex++;
    if (currentCarIndex == myCars.size()) currentCarIndex = 0;
}
void MyCart::MoveBackward() {
    currentCarIndex--;
    if (currentCarIndex == -1) currentCarIndex = myCars.size() - 1;
}

void MyCart::NewIndex() {
    currentCarIndex = 0;
}

void MyCart::MoveNext_Limuzina() {

    MoveForward();
    while(myCars[currentCarIndex]->toName() != "Limuzina")
        MoveForward();
}
void MyCart::MoveNext_MasinaDeCurse() {
    MoveForward();
     while (myCars[currentCarIndex]->toName() != "MasinaDeCurse")
            MoveForward();
}
void MyCart::MoveNext_SUV() {
    MoveForward();
     while (myCars[currentCarIndex]->toName() != "SUV")
            MoveForward();
}
void MyCart::MoveNext_MasinaSport() {
    MoveForward();
     while (myCars[currentCarIndex]->toName() != "MasinaSport")
            MoveForward();
}



void MyCart::MovePrev_Limuzina() {
    MoveBackward();
     while (myCars[currentCarIndex]->toName() != "Limuzina")
            MoveBackward();
}
void MyCart::MovePrev_MasinaDeCurse() {
    MoveBackward();
    while (myCars[currentCarIndex]->toName() != "MasinaDeCurse")
            MoveBackward();
}
void MyCart::MovePrev_SUV() {
    MoveBackward();
    while (myCars[currentCarIndex]->toName() != "SUV")
            MoveBackward();
}
void MyCart::MovePrev_MasinaSport() {
    MoveBackward();
    while (myCars[currentCarIndex]->toName() != "MasinaSport")
            MoveBackward();
}

int MyCart::GetCurrentCarIndex() {
    return currentCarIndex;
}

bool MyCart::IsInCart_Limuzina(){
    for(int i = 0; i < myCars.size() ; ++i)
        if (myCars[i]->toName() == "Limuzina") return true;
    return false;
}

bool MyCart::IsInCart_MasinaDeCurse(){
    for(int i = 0; i < myCars.size() ; ++i)
        if (myCars[i]->toName() == "MasinaDeCurse") return true;
    return false;
}

bool MyCart::IsInCart_SUV(){
    for(int i = 0; i < myCars.size() ; ++i)
        if (myCars[i]->toName() == "SUV") return true;
    return false;
}

bool MyCart::IsInCart_MasinaSport(){
    for(int i = 0; i < myCars.size() ; ++i)
        if (myCars[i]->toName() == "MasinaSport") return true;
    return false;
}


