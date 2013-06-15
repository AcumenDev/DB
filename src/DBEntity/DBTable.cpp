#include "DBTable.h"
namespace DBEntity {

void DBTable::SetTableName(std::string tableName) {
    _TableName=tableName;
}

std::string DBTable::GetTableName() const {
    return _TableName;
}

DBTable::DBTable(std::string tableName) {
    SetTableName(tableName);
}
}//end namespace DBEntity
