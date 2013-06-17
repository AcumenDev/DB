#include "DBTableColumn.h"
namespace DBEntity {

std::string DBTableColumn::GetColumnName() const {
    return _ColumnName;
}
void DBTableColumn::SetColumnName(std::string columnName) {
    _ColumnName=columnName;
}

Core::DataType DBTableColumn::GetColumnDataType() const {
    return _ColumnDataType;
}
void DBTableColumn::SetColumnDataType(Core::DataType dataType) {
    _ColumnDataType=dataType;
}

DBTableColumn::DBTableColumn(std::string columnName, Core::DataType dataType) {
    //ctor
    SetColumnName(columnName);
    SetColumnDataType(dataType);
}
} //end Namespace DBEntity
