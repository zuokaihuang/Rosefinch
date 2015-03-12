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
    AutoSpinLock _l(&lock);
    ++m_value;
}

void AtomInt::dec(){
    AutoSpinLock _l(&lock);
    --m_value;
}

void AtomInt::add(int value){
    AutoSpinLock _l(&lock);
    m_value += value;
}

int const AtomInt::get(){
    AutoSpinLock _l(&lock);
    return m_value;
}
