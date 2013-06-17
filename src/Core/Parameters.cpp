#include "Parameters.h"

namespace Core
{

Parameters::Parameters(int argc, char *argv[])
{
    for (int x=1; x<argc; x++)
    {
        std::cout<<argv[x];

    }


//
//    char* pathToOutputFiles=argv[1];
//    char* pathToDb=argv[2];
//    char* dbType=argv[3];
//    char* langType=argv[4];
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

Language Parameters::GetLanguage() const
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
