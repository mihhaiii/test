#include "CheckBoxManager.h"

CheckBoxManager::CheckBoxManager()
{
    //ctor
}

CheckBoxManager::~CheckBoxManager()
{
    //dtor
}

void CheckBoxManager::addBox(CheckBox* c) {
    checkBoxes.push_back(c);
}
void CheckBoxManager::drawAll(sf::RenderWindow& window) {
    for(auto box:checkBoxes) {
        box->show(window);
    }
}
void CheckBoxManager::checkBoxAtPos(int pos) {
    for(auto box:checkBoxes) {
        box->setCheck(false);
    }
    checkBoxes[pos]->setCheck(true);
}
