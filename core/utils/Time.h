#ifndef TIME_H
#define TIME_H

#include <stdlib.h>

namespace rosefinch {


class Time
{
public:
    Time();
    Time(size_t sec, size_t usec);
    ~Time();
    static Time* now();
    static void sleep(Time *time);
    size_t us(){
        return sec*1000*1000 + usec;
    }
    size_t sec;
    size_t usec;
};

}

#endif // TIME_H
