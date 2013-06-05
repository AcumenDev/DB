#ifndef DBMYSQL_H
#define DBMYSQL_H
#include "../DBBase.h"
namespace DB {
class DBMySql : public  DBBase {
public:
    DBMySql();
    virtual ~DBMySql();
    /** @brief (one liner)
      *
      * (documentation goes here)
      */
    void Close() override;
    /** @brief (one liner)
      *
      * (documentation goes here)
      */
    std::string GetDBName() const;
    void Connect(std::string patch, std::string login, std::string password)  override ;
    std::vector<std::string> GetTables() const override;
    std::vector<std::shared_ptr<TableInfo>> GetTableInfo(std::string tableName) const override;
protected:
private:
};
}
#endif // DBMYSQL_H
