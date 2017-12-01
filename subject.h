#ifndef _SUBJECT_H
#define _SUBJECT_H

#include <vector>
#include "observer.h"

class subject {

public:
//attach playlist listner by passing a self refrence playlist will be poped to the back of the list
    virtual void subscribe(observer *master, observer *sub, subject *p);
//detach playlist send refrence pointer serch for playlist in vector once found remove playlist from vector
    virtual void unsub(observer *master, observer *sub, subject *p);
    virtual void notify(subject *t, int state, int subId);

private:
    std::vector<observer*> followers;
};

#endif //OBSERVER_SUBJECT_H
