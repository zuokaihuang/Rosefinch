#ifndef MUTEX_H
#define MUTEX_H

#include <pthread.h>
#if defined( __APPLE__ )
// for spinlock, Apple's pthread not support spinlock
#include <libkern/OSAtomic.h>
#endif
namespace rosefinch {

class Mutex;
class AutoMutex;
class Spinlock;
class AutoSpinlock;
class Conditon;

class Mutex
{
public:
    Mutex();
    ~Mutex();
    void lock();
    bool trylock();
    void unlock();
    pthread_mutex_t* getLock(){return &m_Lock;}
protected:
    pthread_mutex_t m_Lock;
};

class AutoMutex{
public:
    AutoMutex(rosefinch::Mutex* mutex){
        m_Mutex = mutex;
        m_Mutex->lock();
    }
    ~AutoMutex(){
        m_Mutex->unlock();
//        delete m_Mutex;
//        m_Mutex = 0;
    }
private:
    Mutex* m_Mutex;
};

class Spinlock
{
public:
    Spinlock();
    ~Spinlock();
    void lock();
    bool trylock();
    void unlock();
private:
#ifdef __APPLE__
    OSSpinLock m_lock;
#else
    pthread_spinlock_t m_lock;
#endif
};

class AutoSpinLock{
public:
    AutoSpinLock(Spinlock* lock){
        m_Spinlock = lock;
        m_Spinlock->lock();
    }
    ~AutoSpinLock(){
        m_Spinlock->unlock();
        delete m_Spinlock;
        m_Spinlock = 0;
    }
private:
    Spinlock* m_Spinlock;
};
// end spinlock

// condition
class Condition{
public:
    Condition();
    ~Condition();
    void wait();
    void wait(unsigned int us);
    void notify();

    Mutex* getMutex(){ return &m_Mutex;}
private:
    pthread_cond_t m_cond;
//    pthread_mutex_t m_mutex;
    Mutex m_Mutex;
};

} // end namespace


#endif // MUTEX_H
