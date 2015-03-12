#include "Memory.h"

namespace rosefinch {

#undef free
void safefree(void** pp){
    Assert(pp!=NULL, "safe free the pointer can't be null");
    if (pp != NULL){
        free(*pp);
        *pp = NULL;
    }
}

}


