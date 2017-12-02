
#ifndef _OBS_H
#define _OBS_H
#include "subject.h"

class observer {
public:
    virtual void update(string pLN, int state, int id, Subject *subject) = 0;
};

#endif //_OBS_H
