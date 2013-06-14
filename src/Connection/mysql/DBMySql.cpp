#include "./DBMySql.h"
namespace DB {

void DBMySql::Close() {
throw  Tools::Exception::NotImplementedException();
}

std::string DBMySql::GetDBName() const {
    throw  Tools::Exception::NotImplementedException();
    return "";
}

void DBMySql::Connect(std::string patch, std::string login, std::string password) {
    throw  Tools::Exception::NotImplementedException();
}

std::vector<std::string> DBMySql::GetTables()const {
    std::vector<std::string> vectorResult;
    throw  Tools::Exception::NotImplementedException();
    return vectorResult;
}

std::vector<std::shared_ptr<TableInfo>> DBMySql::GetTableInfo(std::string tableName)const {
    throw  Tools::Exception::NotImplementedException();
}
}//end namespace DB
