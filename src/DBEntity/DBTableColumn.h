#ifndef DBTABLECOLUMN_H
#define DBTABLECOLUMN_H
#include <iostream>
#include "../Connection/TableInfo.h"

class DBTableColumn {
public:
    DBTableColumn(std::string name, DB::DataType type);
    std::string ColumnName;
    DB::DataType ColumnType;
    virtual ~DBTableColumn(){};
protected:
private:
};
#endif // DBTABLECOLUMN_H
