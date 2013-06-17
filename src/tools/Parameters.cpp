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
return _OutputDirPath
}

std::string Parameters::GetDBType() const
{
return _DBtype;
}

std::string Parameters::GetLanguage() const
{
return _Language;
}

void Parameters::SetPathToDB(std::string path)
{
_PathToDB=path;
}

void Parameters::SetOutputPath(std::string path)
{
_OutputPath=path;
}

void Parameters::SetDBType()
{
_DBType=DB::
}

void Parameters::SetLanguage()
{

}

Parameters::~Parameters()
{


}
}
