#include <iostream>
#include "src/Connection/DBConnection.h"
#include "src/tools/Log/LoggingSystem.h"
using namespace std;

int main() {
    Connection::DBConnection var;

    LoggingSystem * Log = LoggingSystem::GetLoggingSystem();

    Log->Write("Hello world!");
//    cout <<  << endl;

DB::DBBase * dbSqlLite =  var.GetConnection(DB::DBType::Sqllite);

dbSqlLite->Connect("122.db","","");
for(auto i : dbSqlLite->GetTables())
    std::cout<<i<<" ";


    return 0;
}
