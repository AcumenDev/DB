#ifndef DBMODEL_H
#define DBMODEL_H
#include "DBTable.h"
namespace DBModel {
class DBModel
{
    public:
        DBModel();
        std::string Name;
        std::vector<DBTable> DBTableList;
        virtual ~DBModel();
    protected:
    private:

};
}

#endif // DBMODEL_H
