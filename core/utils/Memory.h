#ifndef MEMORY_H
#define MEMORY_H

#include <assert.h>

namespace rosefinch {

#define Assert(cond, msg) assert(cond && msg);

void safefree(void** pp);
template<typename T>
inline void safedelete(T pp){
    Assert(pp!=NULL, "safe delete the pointer can't be null");
    if (pp != NULL){
        delete(*pp);
        *pp = NULL;
    }
}

//#define free(e) assert(0 && "free() call not safe, use safefree()");

}


#endif // MEMORY_H
