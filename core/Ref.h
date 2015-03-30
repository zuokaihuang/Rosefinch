#ifndef REF_H
#define REF_H

#include <core/utils/Atom.h>
#include <vector>
#include <core/utils/Lock.h>
#include <core/utils/Memory.h>
#include <core/utils/Logger.h>

namespace rosefinch {

class Object{};

class Ref : public Object
{
public:
    Ref();
    virtual ~Ref();
    void retain();
    void release();
    void autorelease();
    virtual void init() = 0;

private:
//    AtomInt m_RefCount;
};

template <typename T>
class RefBase : public Ref{
protected:
    RefBase():Ref(){}
    virtual ~RefBase(){}
protected:
    void* operator new (std::size_t size) noexcept{
        return ::operator new (size);
    }
    void* operator new (std::size_t size, const std::nothrow_t &) noexcept{
        return ::operator new (size);
    }
private:
    void* operator new[] (std::size_t ) noexcept {return nullptr;} // not support new[]

public:
    static T* create(){
        T* t =new (std::nothrow) T();
        t->init();
        return t;
    }
};


class AutoRef{
public:
    AutoRef();
    ~AutoRef();

    void add(Ref* &ref);
    void add_sp(sp<Ref> *&spRef);
    void release();
    void release_sp();
    // a interface, callback in release(), be called removing item.
    virtual void onRemove(Ref*){}

    size_t size();
private:
//    std::vector<Ref*> m_Refs;
    Spinlock* m_pSpinlock;
    std::vector<sp<Ref>*> m_spRefs;
};


}


#endif // REF_H
