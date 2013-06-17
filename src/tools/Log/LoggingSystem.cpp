#include "LoggingSystem.h"

namespace Tools {
std::shared_ptr<LoggingSystem> LoggingSystem::_LoggingSystem=nullptr;

std::shared_ptr<LoggingSystem> LoggingSystem::GetLoggingSystem() {

    if(_LoggingSystem ==nullptr) {
        _LoggingSystem =  std::shared_ptr<LoggingSystem> (new LoggingSystem());
    }
    return _LoggingSystem;
}

void LoggingSystem::Write(std::string msg,  LogType type) {
    _LogOutSystem->Write(msg, type);
}

}//end namespace Tools
