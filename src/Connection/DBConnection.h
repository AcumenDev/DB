#ifndef DBCONNECTION_H
#define DBCONNECTION_H
#include "DefDB.h"
#include "../utils/utils.h"
#include "sqllite/DBSqllite.h"
#include "mysql/DBMySql.h"

namespace Connection {
class DBConnection {
public:
    /** Default constructor */
    DBConnection();
    static DB::DBBase  * GetConnection(DB::DBType dbType);
    /** Default destructor */
    virtual ~DBConnection();
protected:
private:
};
}
#endif // DBCONNECTION_H
