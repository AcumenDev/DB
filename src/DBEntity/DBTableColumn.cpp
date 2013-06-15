#include "DBTableColumn.h"
namespace DBEntity {
DBTableColumn::DBTableColumn(std::string name, DB::DataType type) {
    //ctor
    this->ColumnName=name;
    this->ColumnType=type;
}
} //end Namespace DBEntity
