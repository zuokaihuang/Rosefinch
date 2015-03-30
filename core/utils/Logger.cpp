#include "Logger.h"
#include "stdarg.h"
#include <iostream>
using namespace std;
#include <core/utils/Lock.h>
using namespace rosefinch;

Logger* Logger::g_pLogger = nullptr;

Logger::Logger()
{
    m_pSpinlock = new Spinlock();

}

Logger::~Logger()
{
    delete m_pSpinlock;
    m_pSpinlock = 0;
}

void Logger::log_(LogLevel level, const char *log){
    AutoLock _l(m_pSpinlock);

    LogItem *item = new LogItem();
    item->id = 0;
    item->level = level;
    item->msg = new std::string(log);
    item->time = Time::now ();
    m_logs.Put (item);
}

void Logger::start (){
    m_bIsRunning = true;
    pthread_create (&m_pid, 0, ThreadEntry, this);
}

void* Logger::ThreadEntry(void*ptr){
    cout <<" m_logs.size ()" << endl;
    Logger* self = (Logger*)ptr;
    while(self->m_bIsRunning){
        LogItem *item= self->m_logs.Take ();
        cout << self->m_logs.size () << ". " <<item->msg->c_str ()<< endl;
        delete item;
    }
    cout << "Logger exit" << endl;
    return 0;
}

void rosefinch::DLog(const char *fmt,...){
    va_list argptr;
    int cnt;
    char buffer[4096];
    memset(buffer, 0, 4096);
    va_start(argptr, fmt);
    cnt = vsprintf(buffer, fmt, argptr);
    va_end(argptr);

    Logger::getInstance ()->log (buffer);
}


