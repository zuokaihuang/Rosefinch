#ifndef LOGGER_H
#define LOGGER_H

#include <list>
#include <core/utils/Time.h>
#include <string>
#include <pthread.h>
#include <core/utils/Collection.h>

namespace rosefinch {
class Spinlock;


enum class LogLevel{
    kDEBUG,
    kINFO,
    kERROR
};

typedef struct LogItem{
    int id;
    LogLevel level;
    Time* time;
    std::string* msg;
    ~LogItem(){
        if(time!=nullptr){
            delete time;
            time=nullptr;
        }
        if (msg!=nullptr){
            delete msg;
            msg = nullptr;
        }
    }
}LogItem;


class Logger
{
private:
    Logger();
    ~Logger();
public:
    static Logger* getInstance(){
        if(g_pLogger == nullptr){
            g_pLogger = new Logger();
            g_pLogger->start ();
        }
        return g_pLogger;
    }
    void log_(LogLevel level, const char* log);
    static void log (const char* log){
        if(g_pLogger != nullptr)
            g_pLogger->log_ (LogLevel::kDEBUG, log);
    }
    void start();
    static void* ThreadEntry(void*);
protected:
    //     std::list<LogItem*> m_logs;
    MessageQueue<LogItem*> m_logs;
    Spinlock* m_pSpinlock;
    bool m_bIsRunning;
    pthread_t m_pid;

    static Logger* g_pLogger;
};

void DLog(const char* fmt, ...);

}

#define logd()


#endif // LOGGER_H
