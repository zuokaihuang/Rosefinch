#ifndef COLLECTION_H
#define COLLECTION_H

#include <core/utils/Lock.h>
#include <list>

namespace rosefinch {
template<typename T>
class MessageQueue{
public:
    MessageQueue(){}
    ~MessageQueue(){}

    void Put(const T&item){
        AutoLock _l(m_Cond.getMutex ());
        m_queue.push_back (item);
        m_Cond.notify ();
    }

    T& Take(){
        AutoLock _l(m_Cond.getMutex ());
        // wait, when the queue is empty
        if (m_queue.size ()==0){
            m_Cond.wait ();
        }
        T& front(m_queue.front ());
        m_queue.pop_front ();

        return front;
    }
    size_t size(){
        AutoLock _l(m_Cond.getMutex ());
        return m_queue.size ();
    }

private:
    Condition m_Cond;
    std::list<T> m_queue;
    size_t m_countTake;
    size_t m_countPut;
};

}
#endif // COLLECTION_H
