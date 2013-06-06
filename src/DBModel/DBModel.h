#ifndef DBMODEL_H
#define DBMODEL_H
#include "DBTable.h"
#include "../Connection/DBBase.h"
namespace DBModel {
class DBModel
{
    public:
        DBModel(std::shared_ptr<DB::DBBase> dbBase);
        std::string DBName;
        std::vector<DBTable> DBTableList;
        virtual ~DBModel();
    protected:
    private:

};
}

#endif // DBMODEL_H
