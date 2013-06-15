#include "DBModel.h"
namespace DBEntity {

void DBModel::SetDBName(std::string dbName) {
    _DBName=dbName;
}

std::string DBModel::DBModel::GetDBName() {
    return _DBName;
}

DBModel::DBModel(std::shared_ptr<DB::DBBase> dbBase) {

    for(auto tableName : dbBase->GetTables()) {

        DBTable table = DBTable(tableName);

        for(auto field : dbBase->GetTableInfo(tableName)) {
            DBTableColumn column =  DBTableColumn(field->GetName(), field->GetType());
            table.DBTableColumnList.push_back(column);
        }

        this->DBTableList.push_back(table);
    }
}
}//end namespace DBEntity
