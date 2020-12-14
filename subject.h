#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
#include "info.h"

class Observer;

class Subject {
    public:
        void attach( Observer* );
        void detach( Observer* );
        void notifyObservers();
        virtual ~Subject()=0;
        virtual Info getInfo() const = 0;

    private:
        std::vector<Observer*> observers;
};

#endif
