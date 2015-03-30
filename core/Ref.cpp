#include "Ref.h"
#include <iostream>
using namespace std;
using namespace rosefinch;

Ref::Ref() : Object()
{

}

Ref::~Ref()
{

}

void Ref::retain(){
//    m_RefCount.inc();
}

void Ref::release(){
//    m_RefCount.dec();
    int cnt =0;// m_RefCount.get();
    if (cnt == 0){
        cout << "this" << this << endl;
//        delete this;
    }
}

void Ref::autorelease(){

}
/* AutoRef */
AutoRef::AutoRef(){
    m_pSpinlock = new Spinlock();
}

AutoRef::~AutoRef(){

}
#include <iostream>
using namespace std;
void AutoRef::add(Ref *&ref){
    sp<Ref> *aSp = new sp<Ref>(&ref);
    cout << "asp:" << **aSp << endl;
    cout << "ref:" << ref << endl;
    cout << "ref." << *(*aSp) << endl;
    cout << "sp :" << aSp << endl;
    add_sp(aSp);
}

void AutoRef::add_sp (sp<Ref>*& spRef){
    AutoLock _(m_pSpinlock);
    m_spRefs.push_back(spRef);
}


void AutoRef::release(){
    release_sp ();
}

#include <iostream>
using namespace std;
void AutoRef::release_sp(){
    std::vector<sp<Ref>*>::iterator it = m_spRefs.begin();
    while(it!=m_spRefs.end()){
        sp<Ref>* sp = *it;
        if(sp != NULL && **sp!=NULL){
            Ref* ref = *(*sp);
            cout << ":" << ref << endl;
            cout << " " << sp << endl;
            cout << " " << *it << endl;
            cout << " " << *(*sp) << endl;
            cout << "." << sp->m_pp << endl;
            cout << " " << *sp->m_pp << endl;
            if( ref != 0){
                onRemove(ref);
                ref->release ();
                m_spRefs.erase(it);
                delete sp;
                ref = 0;
                it = m_spRefs.begin();
                continue;
            }
        }
        it++;
    }
}

size_t AutoRef::size (){
    AutoLock _(m_pSpinlock);
    return m_spRefs.size ();
}

