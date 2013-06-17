#include <iostream>
#include "src/Connection/DBConnection.h"
#include "src/Tools/Log/LoggingSystem.h"
#include "src/DBEntity/DBModel.h"
#include "src/Tools/FileSystem.h"
#include "src/Tools/TemplateHelper.h"
#include "src/Core/Settings.h"
#include "src/Core/Parameters.h"
#include "src/CodeGeneration/Cpp/CGCpp.h"
using namespace std;

int main(int argc, char **argv)
{
    std::shared_ptr<LoggingSystem> Log = LoggingSystem::GetLoggingSystem();

    Core::Parameters parameters(argc, argv);

    Log->Write("Hello world!");//<<" 123";

    std::shared_ptr<Core::Settings> settings= Core::Settings::GetSettings();
    settings->SetOutputDir("OutputDB");
    settings->SetOutputDirTables("Tables");
    settings->SetTemplateDir("Templates");
    std::shared_ptr<DB::DBBase> dbSqlLite = Connection::DBConnection::GetConnection(Core::DBType::Sqllite);

    dbSqlLite->Connect("TestDB.db","","");

    DBEntity::DBModel dbModel =  DBEntity::DBModel(dbSqlLite);

    CG::CGCpp cgCpp;
    cgCpp.SetDBModel(dbModel);
    cgCpp.Generate();

    return 0;
}



