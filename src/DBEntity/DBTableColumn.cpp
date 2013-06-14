#include "DBTableColumn.h"

DBTableColumn::DBTableColumn(std::string name, DB::DataType type) {
    //ctor
    this->ColumnName=name;
    this->ColumnType=type;
}
