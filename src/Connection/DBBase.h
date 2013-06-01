#ifndef DBBASE_H
#define DBBASE_H
#include <iostream>
#include <vector>
#include "../tools/Log/LoggingSystem.h"
namespace DB {
///Базовый класс для подключения к бд
class DBBase {
public:
    /** Default constructor */
    DBBase() ;
    virtual  void Connect(std::string patch, std::string login, std::string password) =0;
    virtual  void  Close()=0;
    virtual std::vector<std::string> GetTables() = 0;
//virtual std::vector<> GetTableInfo(std:string tableName) = 0;
    /** Default destructor */
    virtual ~DBBase();
protected:
private:
};
}
#endif // DBBASE_H
