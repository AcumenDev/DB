#ifndef DBTABLECOLUMN_H
#define DBTABLECOLUMN_H
#include <iostream>
#include "../Connection/TableInfo.h"
namespace DBEntity {
class DBTableColumn {
public:
    DBTableColumn(std::string name, DB::DataType type);
    std::string ColumnName;
    DB::DataType ColumnType;
    virtual ~DBTableColumn(){};
protected:
private:
};
} //end Namespace DBEntity
#endif // DBTABLECOLUMN_H
