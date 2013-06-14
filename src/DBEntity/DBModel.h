#ifndef DBMODEL_H
#define DBMODEL_H
#include "DBTable.h"
#include "../Connection/DBBase.h"

namespace DBEntity {
class DBModel {
public:
    DBModel(){};
    DBModel(std::shared_ptr<DB::DBBase> dbBase);
    std::string DBName;
    std::vector<DBTable> DBTableList;
    virtual ~DBModel(){};
protected:
private:
};
}//end namespace DBEntity
#endif // DBMODEL_H
