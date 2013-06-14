#include "DBModel.h"
namespace DBEntity {

DBModel::DBModel(std::shared_ptr<DB::DBBase> dbBase) {
    this->DBName=dbBase->GetDBName();

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
