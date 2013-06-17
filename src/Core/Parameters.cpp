#include "Parameters.h"

namespace Parameters
{
Parameters::Parameters()
{

}

std::string Parameters::GetPathToDB() const
{
return _PathToDB;
}

std::string Parameters::GetOutputDirPath() const
{
return _OutputDirPath;
}

Core::DBType Parameters::GetDBType() const
{
return _DBType;
}

Core::Language Parameters::GetLanguage() const
{
return _Language;
}

void Parameters::SetPathToDB(std::string path)
{
_PathToDB=path;
}

void Parameters::SetOutputPath(std::string path)
{
_OutputDirPath=path;
}

void Parameters::SetDBType(Core::DBType type)
{
_DBType=type;
}

void Parameters::SetLanguage(Core::Language type)
{
_Language=type;
}

Parameters::~Parameters()
{


}
}
