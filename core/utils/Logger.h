#ifndef LOGGER_H
#define LOGGER_H

namespace rosefinch {
class Logger
{
    typedef
    enum {
        kDEBUG,
        kINFO,
        kERROR
    }LogLevel;

public:
    Logger();
    ~Logger();
    static void log(LogLevel level, const char* log);
};
}

#define logd()


#endif // LOGGER_H
