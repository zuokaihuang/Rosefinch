#ifndef REF_H
#define REF_H

#include <core/utils/Atom.h>
#include <vector>
#include <core/utils/Lock.h>

namespace rosefinch {
class Ref
{
public:
    Ref();
    virtual ~Ref();
    void retain();
    void release();
    void autorelease();

private:
    AtomInt m_RefCount;
};

class AutoRef{
public:
    AutoRef();
    ~AutoRef();

    void add(Ref* ref);
    void release();
    // a interface, callback in release(), be called removing item.
    virtual void onRemove(Ref*){}
private:
    std::vector<Ref*> m_Refs;
    Spinlock m_Spinlock;
};

}


#endif // REF_H
