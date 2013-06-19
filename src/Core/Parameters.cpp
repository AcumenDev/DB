#include "Parameters.h"

namespace Core
{

Parameters::Parameters(int argc, char *argv[], std::shared_ptr<Core::Settings> settings)
{
    _Log =  Tools::LoggingSystem::GetLoggingSystem();
    opterr=0; //отключение вывода ошибок

    int rez=0;

    while ( (rez = getopt(argc,argv,"hp:o:l:d:")) != -1)
    {
        switch (rez)
        {
        case 'h':
        {
            _Log->Write(" -p Path to DB \n -o Path to output folder \n -l Language \n -d Type of DB");
            break;
        }
        case 'p':
        {
//            _Log->Write("Argument -p is found : "+ optarg);
            SetPathToDB(optarg);
            break;
        }
        case 'o':
        {
//              _Log->Write("Argument -o is found : "+ optarg);
            SetPathToOutputDir(optarg);
            break;
        }
        case 'l':
        {
// TODO (grey#1#): сделать выбор языка

            break;
        }
        case 'd':
        {
// TODO (grey#1#): сделать выбор типа db

            break;
        }
        case '?':
        {
            printf("Error found bla bla!\n");
            break;
        }
        };
    };



    settings->SetOutputDir(GetPathToOutputDir());
    settings->SetDBType(GetDBType());
    settings->SetPathToDB(GetPathToDB());
    settings->SetLanguage(GetLanguage());
}


std::string Parameters::GetPathToDB() const
{
    return _PathToDB;
}

std::string Parameters::GetPathToOutputDir() const
{
    if (_PathToOutputDir=="")
        return "OutputDB";
    else
        return _PathToOutputDir;
}

Core::DBType Parameters::GetDBType() const
{
    if (_DBType==NULL)
        return Core::Sqllite;
    else
        return _DBType;
}

Language Parameters::GetLanguage() const
{
    if (_Language==NULL)
        return Core::Cpp;
    else
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
