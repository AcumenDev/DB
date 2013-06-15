#ifndef DBMODEL_H
#define DBMODEL_H
#include "DBTable.h"
#include "../Connection/DBBase.h"

namespace DBEntity {
class DBModel {
public:
    DBModel() {};
    DBModel(std::shared_ptr<DB::DBBase> dbBase);
    std::string GetDBName() const;
    void SetDBName(std::string dbName);
    std::vector<DBTable> DBTableList;
    virtual ~DBModel() {};
protected:
private:
    std::string _DBName;
};
}//end namespace DBEntity
#endif // DBMODEL_H
