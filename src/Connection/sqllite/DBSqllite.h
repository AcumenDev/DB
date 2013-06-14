#ifndef DBSQLLITE_H
#define DBSQLLITE_H
#include <memory>
#include "../DBBase.h"
#include "../../../extern_lib/sqlite3/include/sqlite3.h"

namespace DB {
class DBSqllite : public  DBBase {
public:
    DBSqllite();

    void Close();

    void Connect(std::string patch, std::string login, std::string password) override;
    std::string GetDBName()const override;
    std::vector<std::string> GetTables() const override;
    std::vector<std::shared_ptr<TableInfo>> GetTableInfo(std::string tableName)const override;
    virtual ~DBSqllite();
protected:
private:
    sqlite3 *ppDb  ;
    //  std::shared_ptr<sqlite3> ppDb;
    int status ;
std::string _NameDB;

    const std::string GET_TABLES_QUERY = "select * from sqlite_master";
};
}
#endif // DBSQLLITE_H
