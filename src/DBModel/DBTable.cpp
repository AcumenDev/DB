#include "DBTable.h"
namespace DBModel
{
DBTable::DBTable(std::string tableName)
{
    this->TableName=tableName;
}

DBTable::~DBTable()
{
    //dtor
}
}
