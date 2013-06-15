#include "DBTable.h"
namespace DBEntity {

std::string DBTable::GetTableName() const {
    return _TableName;
}

void DBTable::SetTableName(std::string tableName) {
    _TableName=tableName;
}

DBTable::DBTable(std::string tableName) {
    SetTableName(tableName);
}
}//end namespace DBEntity
