#ifndef __SATISFIED_CLIENT_EVENT_H__
#define __SATISFIED_CLIENT_EVENT_H__

#include <string>
#include "RandomEvent.h"

class SatisfiedClientEvent: public RandomEvent
{
public:
    SatisfiedClientEvent(std::string description);

    virtual void EventStart();

protected:

private:

};

#endif // __SATISFIED_CLIENT_EVENT_H__
