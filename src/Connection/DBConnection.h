#ifndef DBCONNECTION_H
#define DBCONNECTION_H
#include "./DefDB.h"
#include "./sqllite/DBSqllite.h"
#include "./mysql/DBMySql.h"
#include "../tools/tools.h"

namespace Connection
{
class DBConnection
{
public:
    DBConnection() {};
    static std::shared_ptr<DB::DBBase> GetConnection(DB::DBType dbType);
    virtual ~DBConnection() {};
protected:
private:
};
} //end namespace Connection
#endif // DBCONNECTION_H
