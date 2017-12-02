#ifndef _SUBJECT_H
#define _SUBJECT_H

#include <vector>
#include <string>
#include "observer.h"
#include <algorithm>
using namespace std;


class Subject
{
private:
    std::vector<observer*> followers;

public:
    void subscribe(observer *master, observer *sub, Subject *p) {
        p->followers.push_back(sub);
    };
    void unsub(observer *master, observer *sub, Subject *p) {
        followers.erase(remove(followers.begin(),followers.end(), sub),followers.end());
    };
    void notify(string pLName, int state, int Id, Subject *subject) {
        for(vector<observer*>::iterator it = followers.begin(); it!=followers.end(); ++it) {(*it)->update(pLName,state,Id,this);}
    };
};


#endif //_SUBJECT_H