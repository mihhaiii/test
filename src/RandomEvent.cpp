#include <iostream>
#include "RandomEvent.h"
using namespace std;

RandomEvent::RandomEvent(string description)
:_description(description)
{

}

string RandomEvent::GetDescription()
{
    return _description;
}

void RandomEvent::SetDescription(string description)
{
    _description = description;
}

void RandomEvent::EventStart()
{
    cout<<"Ready! Set! Go!\n";
}
