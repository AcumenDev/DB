#ifndef DBSQLLITE_H
#define DBSQLLITE_H
#include "../DBBase.h"
#include "sqlite3.h"

namespace DB {
class DBSqllite : public  DBBase {
public:
    DBSqllite();

    void Close();

    void Connect(std::string patch, std::string login, std::string password);
    std::vector<std::string> GetTables();
    virtual ~DBSqllite();
protected:
private:

     int CallbackQueryGetTables(void *data, int coln, char **rows, char **colnm);
     sqlite3 *ppDb  ;
     int status ;


     const std::string GET_TABLES_QUERY = "select * from sqlite_master";
};
}
#endif // DBSQLLITE_H
