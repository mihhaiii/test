#include "MasinaManager.h"

MasinaManager::MasinaManager()
{
    currentCarIndex = 0;
}

MasinaManager::~MasinaManager()
{
    //dtor
}

void MasinaManager::AddCar(Masina* m) {
    carList.push_back(m);
}
void MasinaManager::DeleteCar(int id) {
    int sz = carList.size();
    for(int i=id;i+1<sz;i++) {
        carList[i] = carList[i + 1];
    }
    carList.pop_back();
    currentCarIndex = 0;
}
void MasinaManager::DeleteCar(Masina* m) {
    int index=0;
    for(auto masina: carList) {
            if ((*masina) == (*m)) {
                DeleteCar(index);
            }
            index++;
    }
}
void MasinaManager::ShadowCar(int id) {
    carList[id]->setState(Epuizat);
}
void MasinaManager::ShadowCar(Masina* m) {
    for(auto masina: carList) if ((*masina) == (*m))
    {
        masina->setState(Epuizat);
    }
}

Masina* MasinaManager::GetCurrentCar() {
    if (currentCarIndex == -1) return NULL;
    if (carList.size() == 0) return NULL;
    return carList[currentCarIndex];
}

void MasinaManager::MoveForward() {
    if (carList.size() == 0) return;
    currentCarIndex++;
    if (currentCarIndex == carList.size()) currentCarIndex = 0;
}
void MasinaManager::MoveBackward() {
    if (carList.size() == 0) return;
    currentCarIndex--;
    if (currentCarIndex == -1) currentCarIndex = carList.size() - 1;
}

int MasinaManager::GetCarsCount(){
    return carList.size();
}

void MasinaManager::moveNext_Limuzina() {
    if (!areLimuzina()) return;
    MoveForward();
        while (carList[currentCarIndex]->toName() != "Limuzina")
            MoveForward();
}
void MasinaManager::moveNext_MasinaDeCurse() {
    if (!areMasinaDeCurse()) return;
    MoveForward();
     while (carList[currentCarIndex]->toName() != "MasinaDeCurse")
            MoveForward();
}
void MasinaManager::moveNext_SUV() {
    if (!areSUV()) return;
    MoveForward();
     while (carList[currentCarIndex]->toName() != "SUV")
            MoveForward();
}
void MasinaManager::moveNext_MasinaSport() {
    if (!areMasinaSport()) return;
    MoveForward();
     while (carList[currentCarIndex]->toName() != "MasinaSport")
            MoveForward();
}



void MasinaManager::movePrev_Limuzina() {
    if (!areLimuzina()) return;
    MoveBackward();
     while (carList[currentCarIndex]->toName() != "Limuzina")
            MoveBackward();
}
void MasinaManager::movePrev_MasinaDeCurse() {
    if (!areMasinaDeCurse()) return;
    MoveBackward();
    while (carList[currentCarIndex]->toName() != "MasinaDeCurse")
            MoveBackward();
}
void MasinaManager::movePrev_SUV() {
    if (!areSUV()) return;
    MoveBackward();
    while (carList[currentCarIndex]->toName() != "SUV")
            MoveBackward();
}
void MasinaManager::movePrev_MasinaSport() {
    if (!areMasinaSport()) return;
    MoveBackward();
    while (carList[currentCarIndex]->toName() != "MasinaSport")
            MoveBackward();
}

int MasinaManager::getCurrentCarIndex() {
    return currentCarIndex;
}





bool MasinaManager::areLimuzina() {
    for(auto m : carList) if (m->toName() == "Limuzina") return true;
    return false;
}
bool MasinaManager::areMasinaSport() {
    for(auto m : carList) if (m->toName() == "MasinaSport") return true;
    return false;
}
bool MasinaManager::areMasinaDeCurse() {
    for(auto m : carList) if (m->toName() == "MasinaDeCurse") return true;
    return false;
}
bool MasinaManager::areSUV() {
    for(auto m : carList) if (m->toName() == "SUV") return true;
    return false;
}





