#ifndef DBBASE_H
#define DBBASE_H
#include <iostream>
#include <vector>
#include <memory>
#include "./TableInfo.h"
#include "../Tools/Log/LoggingSystem.h"
#include "../Tools/tools.h"

namespace DB {

///Базовый класс для подключения к бд
class DBBase {
public:
    DBBase() ;
    virtual  void Connect(std::string patch, std::string login, std::string password) =0;
    virtual  void  Close()=0;
    virtual std::string GetDBName() const =0;
    virtual std::vector<std::string> GetTables() const = 0;
    virtual std::vector<std::shared_ptr<TableInfo>> GetTableInfo(std::string tableName) const = 0;
    virtual ~DBBase() {};
protected:
    std::shared_ptr<LoggingSystem> _Log;
private:
};
}//end namespace DB
#endif // DBBASE_H
