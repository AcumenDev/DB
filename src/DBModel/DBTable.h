#ifndef DBTABLE_H
#define DBTABLE_H
#include <vector>
#include "DBTableColumn.h"
namespace DBModel
{
class DBTable
{
public:
    DBTable(std::string tableName);
    std::string TableName;
    std::vector<DBTableColumn> DBTableColumnList;
    virtual ~DBTable();
protected:
private:
};
}

#endif // DBTABLE_H
