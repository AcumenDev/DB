#include <iostream>
#include "src/Connection/DBConnection.h"
#include "src/tools/Log/LoggingSystem.h"
using namespace std;

int main() {
    Connection::DBConnection var;

   // LoggingSystem * Log = LoggingSystem::GetLoggingSystem();

 //   Log->Write("Hello world!");

    std::shared_ptr<DB::DBBase> dbSqlLite =  var.GetConnection(DB::DBType::Sqllite);
    dbSqlLite->Connect("122.db","","");
    for(auto& tableName : dbSqlLite->GetTables()) {
        std::cout<<tableName<<" "<<std::endl;
        for(auto& field : dbSqlLite->GetTableInfo(tableName))
            std::cout<<field->GetName()<<" "<<field->GetTypeStr()<<std::endl;
        std::cout<<std::endl;
    }

    return 0;
}
