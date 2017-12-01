#ifndef _SUBJECT_H
#define _SUBJECT_H

#include <vector>
#include <string>
#include "observer.h"
#include <algorithm>
using namespace std;


class Subject {

public:
//attach playlist listner by passing a self refrence playlist will be poped to the back of the list
    void subscribe(observer *master, observer *sub, Subject *p);
//detach playlist send refrence pointer serch for playlist in vector once found remove playlist from vector
    void unsub(observer *master, observer *sub, Subject *p);
    void notify(string pLName, int state, int subId);

private:
    std::vector<observer*> followers;
};

void Subject::subscribe(observer *master, observer *sub, Subject *p) {
    p->followers.push_back(sub);
}

void Subject::unsub(observer *master, observer *sub, Subject *p) {
    followers.erase(remove(followers.begin(),followers.end(), sub),followers.end());
}

void Subject::notify(string pLName, int state, int subId) {
    for(vector<observer*>::iterator it = followers.begin(); it!=followers.end(); ++it) {
        (*it)->update(pLName,state,subId);
    }

}
#endif //_SUBJECT_H