#ifndef LOGGINGSYSTEM_H
#define LOGGINGSYSTEM_H
#include <iostream>
#include <memory>
#include "ILog.h"
#include "LogStdConsole.h"

class LoggingSystem : public ILog {
public:
    virtual ~LoggingSystem() {}
    static std::shared_ptr<LoggingSystem> GetLoggingSystem();
    void Write(std::string msg, LogType type = LogType::Messages) override ;
    LoggingSystem(const LoggingSystem&) = delete;
private:
    ILog * _LogOutSystem ;
    static     std::shared_ptr<LoggingSystem> _LoggingSystem;
    LoggingSystem() {
        //по умолчанию создаеться лог для вывода на стандартную консоль
        _LogOutSystem = new LogStdConsole();
    }
};
#endif // LOGGINGSYSTEM_H
