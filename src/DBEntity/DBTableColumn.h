#ifndef DBTABLECOLUMN_H
#define DBTABLECOLUMN_H
#include <iostream>
#include "../Connection/TableInfo.h"
#include "../tools/DefDB.h"
namespace DBEntity {
class DBTableColumn {
public:
    DBTableColumn(std::string name, Core::DataType type);
    std::string GetColumnName() const;
    Core::DataType GetColumnDataType() const;
    void SetColumnName(std::string columnName);
    void SetColumnDataType(Core::DataType dataType);
    virtual ~DBTableColumn() {};
protected:
private:
    std::string _ColumnName;
    Core::DataType _ColumnDataType;
};
} //end Namespace DBEntity
#endif // DBTABLECOLUMN_H
