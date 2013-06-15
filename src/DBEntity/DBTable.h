#ifndef DBTABLE_H
#define DBTABLE_H
#include <vector>
#include "DBTableColumn.h"

namespace DBEntity {
class DBTable {
public:
    DBTable(std::string tableName);
    std::string GetTableName() const;
    void SetTableName (std::string tableName);
    std::vector<DBTableColumn> DBTableColumnList;
    virtual ~DBTable() {};
protected:
private:
    std::string _TableName;
};
}//end namespace DBEntity
#endif // DBTABLE_H
