#include "./DBBase.h"
namespace DB {
DBBase::DBBase() {
    //ctor
    _Log =  LoggingSystem::GetLoggingSystem();
}
}//end namespace DB
