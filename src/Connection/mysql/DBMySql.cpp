#include "DBMySql.h"
namespace DB {
DBMySql::DBMySql() {
    //ctor
}

DBMySql::~DBMySql() {
    //dtor
}

void DBMySql::Close()
{

}
std::string DBMySql::GetDBName()
{
return "";
}

void DBMySql::Connect(std::string patch, std::string login, std::string password)
{

}
std::vector<std::string> DBMySql::GetTables()
{
    std::vector<std::string> vectorResult;
    return vectorResult;
}
std::vector<TableInfo> DBMySql::GetTableInfo(std::string tableName)
{
  throw  Tools::NotImplementedException();
}

}
