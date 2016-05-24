#include <iostream>
#include "SatisfiedClientEvent.h"
using namespace std;

SatisfiedClientEvent::SatisfiedClientEvent(string description)
:RandomEvent(description)
{

}

void SatisfiedClientEvent::EventStart()
{
    cout<<"Hurray!\n";
}
