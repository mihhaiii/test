#ifndef __STOLEN_CAR_EVENT_H__
#define __STOLEN_CAR_EVENT_H__

#include <string>
#include "RandomEvent.h"

class StolenCarEvent: public RandomEvent
{
public:
    StolenCarEvent(std::string description);

    virtual void EventStart();

protected:

private:
};

#endif // __STOLEN_CAR_EVENT_H__
