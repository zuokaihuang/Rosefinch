#include "Atom.h"

using namespace rosefinch;

AtomInt::AtomInt() :
    m_value(0)
{

}

AtomInt::~AtomInt()
{

}

void AtomInt::inc(){
    AutoLock _l(&lock);
    ++m_value;
}

void AtomInt::dec(){
    AutoLock _l(&lock);
    --m_value;
}

void AtomInt::add(int value){
    AutoLock _l(&lock);
    m_value += value;
}

int AtomInt::get(){
    AutoLock _l(&lock);
    return m_value;
}
