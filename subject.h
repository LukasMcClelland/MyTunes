#ifndef _SUBJECT_H
#define _SUBJECT_H

#include <vector>
#include <string>
#include "observer.h"
#include <algorithm>
#include <iostream>

using namespace std;

class Playlist;
class Subject
{
private:
    vector<observer*> followers;

public:
    void subscribe(observer *master, observer *sub, Subject *p) {
        p->followers.push_back(sub);
    };
    void unsub(observer *master, observer *sub, Subject *p) {
        for(vector<observer*>::iterator it = followers.begin(); it != followers.end(); ++it){
            if((*it) == sub){
                followers.erase(it);
                break;
            }
        }
    };
    void notify(string pLName, int state, int Id, Playlist *pl) {
        for(vector<observer*>::iterator it = followers.begin(); it!=followers.end(); ++it) {
            (*it)->update(pLName,state,Id,pl);
        }
    };
};


#endif //_SUBJECT_H
