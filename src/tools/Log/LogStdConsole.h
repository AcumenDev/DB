#ifndef LOGSTDCONSOLE_H
#define LOGSTDCONSOLE_H

#include "ILog.h"

class LogStdConsole : public ILog
 {
public:
    LogStdConsole();
    virtual ~LogStdConsole();

    void Write(std::string msg, LogType type = LogType::Messages)    override;
   // ILog operator<<(const char* msg)override;
protected:
private:
};

#endif // LOGSTDCONSOLE_H
