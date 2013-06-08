#include "DBTable.h"
namespace DBEntity {
DBTable::DBTable(std::string tableName) {
    this->TableName=tableName;
}

DBTable::~DBTable() {
    //dtor
}
}
