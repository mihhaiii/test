#include "Limuzina.h"

Limuzina::Limuzina()
{
    //ctor
}
Limuzina::Limuzina(Brands b, Models m, int x ,int y)
: Masina(b,m,x,y)
{
    passangerCapacity = 4 + rand() % 7;
    length = 5 + (rand() % 20) / 10.f;
}

Limuzina::~Limuzina()
{
    //dtor
}

void Limuzina::showImage(sf::RenderWindow& window) {
    Masina::showImage(window);
}
void Limuzina::showInfo(sf::RenderWindow& window) {
    Masina::showInfo(window);
}
string Limuzina::toName() {
    return "Limuzina";
}

void Limuzina::ShowDetail(sf::RenderWindow&)
{

}

