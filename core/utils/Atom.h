#ifndef ATOM_H
#define ATOM_H

#include <core/utils/Lock.h>

namespace rosefinch {
class AtomInt
{
public:
    AtomInt();
    ~AtomInt();
    void inc();
    void dec();
    void add(int value);
    const int get();
private:
    int m_value;
    Spinlock lock;
};

}

#endif // ATOM_H
