#include "./DBMySql.h"
namespace DB {
DBMySql::DBMySql() {
    //ctor
}

DBMySql::~DBMySql() {
    //dtor
}

void DBMySql::Close() {

}
std::string DBMySql::GetDBName() const {
    return "";
}

void DBMySql::Connect(std::string patch, std::string login, std::string password) {

}
std::vector<std::string> DBMySql::GetTables()const {
    std::vector<std::string> vectorResult;
    return vectorResult;
}
std::vector<std::shared_ptr<TableInfo>> DBMySql::GetTableInfo(std::string tableName)const {
    throw  Tools::Exception::NotImplementedException();
}

}
