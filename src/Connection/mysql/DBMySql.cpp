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

void DBMySql::Connect()
{

}
std::vector<std::string> DBMySql::GetTables()
{
    std::vector<std::string> vectorResult;
    return vectorResult;
}
}
