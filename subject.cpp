#include <algorithm>
#include "observer.h"
#include "subject.h"
using namespace std;

void subject::subscribe(observer *master, observer *sub, subject *p) {
    p->followers.push_back(sub);
}

void subject::unsub(observer *master, observer *sub, subject *p) {
    followers.erase(remove(followers.begin(),followers.end(), sub),followers.end());
}

void subject::notify(subject *t, int state, int subId) {
    for(vector<observer*>::iterator it = followers.begin(); it!=followers.end(); ++it) {
        (*it)->update(t,state,subId);
    }

}
