#include "Parameters.h"

namespace Core
{

Parameters::Parameters(int argc, char *argv[], std::shared_ptr<Core::Settings> settings)
{
    SetDBType(Core::Sqllite);
    SetLanguage(Core::Cpp);
    SetPathToDB(std::string(argv[1]));
    SetPathToOutputDir(std::string(argv[2]));

    settings->SetOutputDir(GetPathToOutputDir());
    settings->SetDBType(GetDBType());
    settings->SetPathToDB(GetPathToDB());
    settings->SetLanguage(GetLanguage());

//    bool parseOkay=true;
//    for (int i=0; i<argc; i++)
//    {
//        std::string val(argv[i]);
//        if (i+1>=argc)
//        {
//            parseError=false;
//            break;
//        }
//        std::string nextOption=std::string(argv[i+1]);
//        if (val=="-dbType")
//        {
//            dbType=nextOption;
//        }
//        else if (val=="-pathToDb")
//        {
//            pathToDB=nextOption;
//        }
//        else if (val=="-langType")
//        {
//            langType=nextOption;
//        }
//        else if (val=="-pathToOutputFiles")
//        {
//            pathToOutputFiles=nextOption;
//        }
//    }
//    SetPathToDB(pathToDB);
//    SetOutputPath(pathToOutputFiles);
//
//    if (dbType=="")
//    {
//
//    }
//    else
//    {
//
//    }
//    if (langType=="")
//    {
//        SetLanguage(Core::Cpp);
//    }

}


std::string Parameters::GetPathToDB() const
{
    return _PathToDB;
}

std::string Parameters::GetPathToOutputDir() const
{
    return _PathToOutputDir;
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

void Parameters::SetPathToOutputDir(std::string path)
{
    _PathToOutputDir=path;
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
