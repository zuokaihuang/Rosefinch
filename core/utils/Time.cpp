#include "Time.h"

#include <sys/time.h>
#include <unistd.h>

using namespace rosefinch;

Time::Time():
    sec(0),
    usec(0)
{

}
Time::Time(size_t sec, size_t usec)
{
    this->sec = sec;
    this->usec = usec;
}

Time::~Time()
{

}

Time* Time::now (){
    timeval tv;
    gettimeofday (&tv, 0);
    Time* time = new Time();
    time->sec = tv.tv_sec;
    time->usec= tv.tv_usec;

    return time;
}

void Time::sleep (Time *time){
    size_t usec = time->sec * 1000 *1000 + time->usec;
    usleep (usec);
}

