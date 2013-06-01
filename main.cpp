#include <iostream>
#include "src/Connection/DBConnection.h"
#include "src/tools/Log/LoggingSystem.h"
using namespace std;

int main() {
    Connection::DBConnection var;

   // LoggingSystem * Log = LoggingSystem::GetLoggingSystem();

 //   Log->Write("Hello world!");

    DB::DBBase * dbSqlLite =  var.GetConnection(DB::DBType::Sqllite);

    dbSqlLite->Connect("122.db","","");
    for(auto tableName : dbSqlLite->GetTables()) {
        std::cout<<tableName<<" "<<std::endl;
        for(auto fild : dbSqlLite->GetTableInfo(tableName))
            std::cout<<fild->GetName()<<" "<<fild->GetTypeStr()<<std::endl;
        std::cout<<std::endl;
    }

    return 0;
}
