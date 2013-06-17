#ifndef DBCONNECTION_H
#define DBCONNECTION_H
#include "../Core/DefDB.h"
#include "sqllite/DBSqllite.h"
#include "mysql/DBMySql.h"
#include "../Tools/tools.h"

namespace Connection {
class DBConnection {
public:
    DBConnection() {};
    static std::shared_ptr<DB::DBBase> GetConnection(Core::DBType dbType);
    virtual ~DBConnection() {};
protected:
private:
};
} //end namespace Connection
#endif // DBCONNECTION_H
