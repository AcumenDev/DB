#include "./DBBase.h"
namespace DB
{
DBBase::DBBase()
{
    _Log =  LoggingSystem::GetLoggingSystem();
}
}//end namespace DB
