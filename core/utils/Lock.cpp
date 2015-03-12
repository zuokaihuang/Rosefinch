#include "Lock.h"
#include <sys/time.h>

using namespace rosefinch;

Mutex::Mutex()
{
    pthread_mutex_init(&m_Lock, 0);
}

Mutex::~Mutex()
{
    pthread_mutex_destroy(&m_Lock);
}

void Mutex::lock(){
    pthread_mutex_lock(&m_Lock);
}

bool Mutex::trylock(){
    return pthread_mutex_trylock(&m_Lock);
}

void Mutex::unlock(){
    pthread_mutex_unlock(&m_Lock);
}

#ifdef __APPLE__
Spinlock::Spinlock():
    m_lock(0)
{
}

Spinlock::~Spinlock(){

}

void Spinlock::lock(){
    OSSpinLockLock(&m_lock);
}
bool Spinlock::trylock(){
    return OSSpinLockTry(&m_lock);
}
void Spinlock::unlock(){
    OSSpinLockUnlock(&m_lock);
}

#elif
Spinlock::Spinlock():
    m_lock(0)
{
    pthread_spin_init(&m_lock);
}
Spinlock::~Spinlock(){
    pthread_spin_destory(&m_lock);
void Spinlock::lock(){
    pthread_spin_lock(&m_lock);
}
bool Spinlock::try_lock(){
    int ret = pthread_spin_trylock(&m_lock);
    return ret != 16; // EBUSY == 16, lock is already taken
}
void Spinlock::unlock(){
    pthread_spin_unlock(&m_lock);
}
#endif

// end spin lock

// condition
Condition::Condition()
{
    pthread_cond_init (&m_cond, 0);
}

Condition::~Condition()
{

}

void Condition::wait (){
    pthread_cond_wait (&m_cond, m_Mutex.getLock ());
}

void Condition::wait (unsigned int us){
    time_t sec = us/(1000*1000);
    time_t usec = us%(1000*1000);
    const struct timeval timeout= {sec, usec};

    struct timeval now;
    struct timespec outtime;

    gettimeofday (&now, 0);
    outtime.tv_sec = now.tv_sec + timeout.tv_sec;
    outtime.tv_nsec = now.tv_usec + timeout.tv_usec;

    pthread_cond_timedwait (&m_cond, m_Mutex.getLock (), &outtime);
}

void Condition::notify (){
    pthread_cond_signal(&m_cond);
}

