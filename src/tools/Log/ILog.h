#ifndef ILOG_H
#define ILOG_H
#include <iostream>
namespace Tools {
enum LogType {
    Debug,
    Messages ,
    Warning,
    Error
};

class ILog {
public:
    ILog() {}
    virtual ~ILog() {}
    virtual  void Write( std::string msg, LogType type = LogType::Messages) =0;
    // virtual  ILog operator<<(const char* x)=0;
protected:
private:
};
}//end namespace Tools
#endif // ILOG_H
