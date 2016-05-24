#ifndef __RANDOM_EVENT_H__
#define __RANDOM_EVENT_H__

#include <string>

class RandomEvent
{
public:
    RandomEvent(std::string description);

    std::string GetDescription();
    void SetDescription(std::string description);

    virtual void EventStart();

protected:
    std::string _description;

private:

};

#endif // __RANDOM_EVENT_H__
