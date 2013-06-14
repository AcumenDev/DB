#include <iostream>
#include "src/Connection/DBConnection.h"
#include "src/tools/Log/LoggingSystem.h"
#include "src/DBEntity/DBModel.h"
#include "src/tools/FileSystem.h"
#include "src/tools/TemplateHelper.h"
#include "src/tools/Settings.h"
#include "src/CodeGeneration/Cpp/CGCpp.h"
using namespace std;

int main() {
   std::shared_ptr<LoggingSystem> Log = LoggingSystem::GetLoggingSystem();

    Log->Write("Hello world!");//<<" 123";
    std::shared_ptr<Core::Settings> settings= Core::Settings::GetSettings();
    settings->SetOutputDir("OutputDB");
    settings->SetTemplateDir("Templates");
    std::shared_ptr<DB::DBBase> dbSqlLite = Connection::DBConnection::GetConnection(DB::DBType::Sqllite);

    dbSqlLite->Connect("TestDB.db","","");

    DBEntity::DBModel dbModel =  DBEntity::DBModel(dbSqlLite);

//    for(const auto& table : dbModel.DBTableList) {
//        std::cout<<table.TableName<<" "<<std::endl;
//
//        for(const auto& field : table.DBTableColumnList )
//            std::cout<<field.ColumnName<<" "<<field.ColumnType<<std::endl;
//
//        std::cout<<std::endl;
//    }
    CG::CGCpp cgCpp;
    cgCpp.SetDBModel(dbModel);
    cgCpp.Generate();

//    Tools::FileSystem::DirCreate("./","lal");

    return 0;
}



