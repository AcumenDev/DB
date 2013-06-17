#ifndef LOGSTDCONSOLE_H
#define LOGSTDCONSOLE_H
#include "ILog.h"

namespace Tools {
class LogStdConsole : public ILog {
public:
    LogStdConsole() {};
    virtual ~LogStdConsole() {};
    void Write(std::string msg, LogType type = LogType::Messages)    override;
protected:
private:
};
}//end namespace Tools
#endif // LOGSTDCONSOLE_H
