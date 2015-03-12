#include "Ref.h"

using namespace rosefinch;

Ref::Ref()
{

}

Ref::~Ref()
{

}

void Ref::retain(){
    m_RefCount.inc();
}

void Ref::release(){
    m_RefCount.dec();
    int cnt = m_RefCount.get();
    if (cnt == 0){
        delete this;
    }
}

void Ref::autorelease(){

}
/* AutoRef */
AutoRef::AutoRef(){

}

AutoRef::~AutoRef(){

}

void AutoRef::add(Ref *ref){
    AutoSpinLock _(&m_Spinlock);
    m_Refs.push_back(ref);
}

void AutoRef::release(){
    std::vector<Ref*>::iterator it = m_Refs.begin();
    while(it!=m_Refs.end()){
        Ref* ref = *it;
        if( ref != 0){
            onRemove(ref);
            ((Ref*)*it)->release();
            m_Refs.erase(it);
            it = m_Refs.begin();
            continue;
        }
        it++;
    }
}
