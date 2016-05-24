#include "MasinaDeCurse.h"

MasinaDeCurse::MasinaDeCurse()
{
    //ctor
}


MasinaDeCurse::~MasinaDeCurse()
{
    //dtor
}
MasinaDeCurse::MasinaDeCurse(Brands b, Models m, int x ,int y)
: Masina(b,m,x,y)
{
    horsePower = 300 + rand() % 400;
    acceleration = 20 + (rand() % 20) / 10.f;
}
void MasinaDeCurse::showImage(sf::RenderWindow& window) {
    Masina::showImage(window);
}
void MasinaDeCurse::showInfo(sf::RenderWindow& window) {
    Masina::showInfo(window);
}

string MasinaDeCurse::toName() {
    return "MasinaDeCurse";
}

void MasinaDeCurse::ShowDetail(sf::RenderWindow&)
{

}



