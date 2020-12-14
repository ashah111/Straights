#ifndef _OBSERVER_H_
#define _OBSERVER_H_
#include <string>

class Subject;

class Observer {
  public:
    virtual void notify( Subject & whoNotified ) = 0;
};

#endif
