#include "LogStdConsole.h"

void LogStdConsole::Write(std::string msg, LogType type) {

    switch (type) {
    case LogType::Debug: {
        std::cout<<"[   Debug  ] "<<msg<<std::endl;
        break;
    }
    case LogType::Messages: {
        std::cout<<"[ Messages ] "<<msg<<std::endl;
        break;
    }
    case LogType::Warning: {
        std::cout<<"[  Warning ] "<<msg<<std::endl;
        break;
    }
    case LogType::Error: {
        std::cout<<"[   Error  ] "<<msg<<std::endl;
        break;
    }
    }
}
