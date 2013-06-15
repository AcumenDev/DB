#ifndef DBMYSQL_H
#define DBMYSQL_H
#include "../DBBase.h"

namespace DB {
class DBMySql : public  DBBase {
public:
    DBMySql() {};
    virtual ~DBMySql() {};
    void Close() override;
    std::string GetDBName() const;
    void Connect(std::string patch, std::string login, std::string password)  override ;
    std::vector<std::string> GetTables() const override;
    std::vector<std::shared_ptr<TableInfo>> GetTableInfo(std::string tableName) const override;
protected:
private:
};
} //end namespace DB
#endif // DBMYSQL_H
