#ifndef _OBSERVER_H
#define _OBSERVER_H
#include "subject.h"

class observer{
public:
    virtual void update(subject *t, int state, int id)=0;
};

#endif //OBSERVER_OBSERVER_H
