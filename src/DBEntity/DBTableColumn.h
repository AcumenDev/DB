#ifndef DBTABLECOLUMN_H
#define DBTABLECOLUMN_H
#include <iostream>
#include "../Connection/TableInfo.h"
namespace DBEntity {
class DBTableColumn {
public:
    DBTableColumn(std::string name, DB::DataType type);
    std::string GetColumnName() const;
    DB::DataType GetDataType() const;
    void SetColumnName(std::string columnName);
    void SetDataType(DB::DataType dataType);
    virtual ~DBTableColumn(){};
protected:
private:
    std::string _ColumnName;
    DB::DataType _DataType;
};
} //end Namespace DBEntity
#endif // DBTABLECOLUMN_H
