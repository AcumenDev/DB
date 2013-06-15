#include "DBTableColumn.h"
namespace DBEntity
{

std::string DBTableColumn::GetColumnName() const
{
    return _ColumnName;
}
void DBTableColumn::SetColumnName(std::string columnName)
{
    _ColumnName=columnName;
}

DB::DataType DBTableColumn::GetDataType() const
{
    return _DataType;
}
void DBTableColumn::SetDataType(DB::DataType dataType)
{
    _DataType=dataType;
}

DBTableColumn::DBTableColumn(std::string columnName, DB::DataType dataType)
{
    //ctor
    SetColumnName(columnName);
    SetDataType(dataType);
}
} //end Namespace DBEntity
