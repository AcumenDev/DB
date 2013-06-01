#ifndef LOGGINGSYSTEM_H
#define LOGGINGSYSTEM_H
#include <iostream>
#include "LogStdConsole.h"
class LoggingSystem
{
public:
    virtual ~LoggingSystem() {}

    static LoggingSystem * GetLoggingSystem();
    void Write(std::string msg, LogType type = LogType::Messages) ;
private:
    ILog * _LogOutSystem ;
    static     LoggingSystem * _LoggingSystem;
    LoggingSystem()
    {
        //по умолчанию создаеться лог для вывода на стандартную консоль
        _LogOutSystem = new LogStdConsole();
    }
};
#endif // LOGGINGSYSTEM_H
