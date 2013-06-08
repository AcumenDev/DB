#include <iostream>
#include "src/Connection/DBConnection.h"
#include "src/tools/Log/LoggingSystem.h"
#include "src/DBEntity/DBModel.h"
#include "src/tools/FileSystem.h"
using namespace std;

int main() {
    Connection::DBConnection var;

    // LoggingSystem * Log = LoggingSystem::GetLoggingSystem();

//   Log->Write("Hello world!");

    std::shared_ptr<DB::DBBase> dbSqlLite =  var.GetConnection(DB::DBType::Sqllite);

    dbSqlLite->Connect("122.db","","");

    DBEntity::DBModel dbModel =  DBEntity::DBModel(dbSqlLite);

    for(auto table : dbModel.DBTableList) {
        std::cout<<table.TableName<<" "<<std::endl;

        for(auto field : table.DBTableColumnList )
            std::cout<<field.ColumnName<<" "<<field.ColumnType<<std::endl;

        std::cout<<std::endl;
    }

//    Tools::FileSystem::DirCreate("./","lal");

    return 0;
}
