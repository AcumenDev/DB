#ifndef ILOG_H
#define ILOG_H

#include <iostream>

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
    virtual  void Write( std::string msg, LogType type = LogType::Messages) {};
protected:
private:
};

#endif // ILOG_H
