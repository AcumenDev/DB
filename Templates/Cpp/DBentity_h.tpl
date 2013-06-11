#ifndef DBENTITYTESTDB_H
#define DBENTITYTESTDB_H
#include "Tables/Test1/Test1_logic.h"

class DBEntityTestDB {
public:
    DBEntityTestDB(std::string patch,  std::string password);
    virtual ~DBEntityTestDB();

    Test1_logic Test1;
protected:
private:
    sqlite3*  _Db;
    int status;
};

#endif // DBENTITYTESTDB_H
