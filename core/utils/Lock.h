#ifndef MUTEX_H
#define MUTEX_H

#include <pthread.h>
#if defined( __APPLE__ )
// for spinlock, Apple's pthread not support spinlock
#include <libkern/OSAtomic.h>
#endif
namespace rosefinch {

class Lock;
class AutoLock;

class Mutex;
class Spinlock;
class Conditon;

class Lock{
public:
    virtual void lock() = 0;
    virtual bool trylock()= 0;
    virtual void unlock() = 0;
};

class AutoLock{
public:
    explicit AutoLock(Lock* lock){
        this->m_pLock = lock;
        this->m_pLock->lock ();
    }
    ~AutoLock(){
        m_pLock->unlock ();
    }

private:
    Lock* m_pLock;
};

class Mutex:public Lock
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


class Spinlock : public Lock
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
    Mutex m_Mutex;
};

} // end namespace


#endif // MUTEX_H
