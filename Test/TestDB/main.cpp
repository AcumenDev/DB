#include <iostream>
#include "../../src/Connection/DefDB.h"
#include "../../src/Connection/DBConnection.h"
//#include "../../src/CodeGeneration/Cpp/CGCpp.h"

using namespace std;
using namespace Connection;
using namespace DB;
int main()
{
    cout << "Hello world!" << endl;
    std::shared_ptr<DBBase> dbSqlLite = DBConnection::GetConnection(DBType::Sqllite);

    return 0;

}
