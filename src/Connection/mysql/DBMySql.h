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
    void Connect() override;
std::vector<std::string> GetTables();
protected:
private:
};
}
#endif // DBMYSQL_H
