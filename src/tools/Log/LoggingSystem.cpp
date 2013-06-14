#include "LoggingSystem.h"

LoggingSystem * LoggingSystem::_LoggingSystem=nullptr;

LoggingSystem * LoggingSystem::GetLoggingSystem() {
    if(_LoggingSystem ==nullptr) {
        _LoggingSystem = new LoggingSystem();
    }
    return _LoggingSystem;
}


void LoggingSystem::Write(std::string msg,  LogType type) {
    _LogOutSystem->Write(msg);
}


//ILog LoggingSystem::operator<<(const char* msg) {
//    _LogOutSystem->Write(msg);
//    return this;
//}
