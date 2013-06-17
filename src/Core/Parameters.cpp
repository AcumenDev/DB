#include "Parameters.h"

namespace Core
{

Parameters::Parameters(int argc, char *argv[])
{

std::string dbType;
std::string pathToDB;
std::string langType;
std::string pathToOutputFiles;

    for (int x=1; x<argc; x++)
    {
        std::string val(argv[x]);

        if (val=="-dbType")
        {

        }

        if (val=="-pathToDb")
        {

        }

        if (val=="-langType")
        {


        }

        if (val=="-pathToOutputFiles")
        {


        }

        std::cout<<"a";
    }
}


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
