#ifndef MEMORY_H
#define MEMORY_H

#include <assert.h>
#include <memory>

namespace rosefinch {

#define Assert(cond, msg) assert(cond && msg);

template <typename T>
class sp{
public:
    explicit sp(T** pp){
        this->m_pp = (void**)pp;
    }

    T* operator*(){
        return get();
    }
    T* get(){
        if (m_pp!=0)
            return (T*)*m_pp;
        return 0;
    }
    void operator delete (void* ptr){
        sp* self = (sp*)ptr;
        delete (T*)*self->m_pp;
        *self->m_pp = 0;
    }

//protected:
    void** m_pp;
};


}


#endif // MEMORY_H
