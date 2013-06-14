#include "./DBSqllite.h"
namespace DB {

DBSqllite::DBSqllite() {
    //ctor
}

DBSqllite::~DBSqllite() {
    //dtor
    Close();
}
void DBSqllite::Close() {
    sqlite3_close(ppDb);
}
std::string DBSqllite::GetDBName() const {
    return _NameDB;
}

void DBSqllite::Connect(std::string path, std::string login, std::string password) {
    std::cout<<"Connect to sqllite : "<<path<<std::endl;
    _NameDB = path;
    status =  sqlite3_open(path.c_str(),&ppDb);
}

std::vector<std::string> DBSqllite::GetTables() const {
    //LoggingSystem * Log = LoggingSystem::GetLoggingSystem();
    std::vector<std::string> vectorResult;
    char  *pSQL2;
    sqlite3_stmt *stmt;
    int rc;
    rc = sqlite3_prepare_v2(ppDb, GET_TABLES_QUERY.c_str(), -1, &stmt, (const char**)&pSQL2);
    if (rc == SQLITE_OK) {
        if (sqlite3_column_count(stmt)) {
            while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
                auto nameTable = sqlite3_column_text(stmt, 1);
                vectorResult.push_back(reinterpret_cast<const char*>(nameTable));
            }
            std::cout<<std::endl;
        }
        sqlite3_finalize(stmt);
    } else {
        std::cout<<"Error: %s\n  "<<sqlite3_errmsg(ppDb);
    }
    return vectorResult;
}

std::vector<std::shared_ptr<TableInfo>> DBSqllite::GetTableInfo(std::string tableName) const {
    std::string  getTableInfoQuery ="PRAGMA table_info( '"+ tableName +"' );";
    std::vector<std::shared_ptr<TableInfo>> result;
    char  *pSQL2;
    sqlite3_stmt *stmt;
    int rc;
    rc = sqlite3_prepare_v2(ppDb, getTableInfoQuery.c_str(), -1, &stmt, (const char**)&pSQL2);
    if (rc == SQLITE_OK) {
        if (sqlite3_column_count(stmt)) {
            while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
                auto nameField = sqlite3_column_text(stmt, 1);
                std::shared_ptr<TableInfo> rowField(new TableInfo());
                DataType typeField = DataType::Text;
                std::string fieldTypeRaw = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
                if("NUMERIC"==fieldTypeRaw )
                    typeField = DataType::Number;
                if("TEXT"==fieldTypeRaw)
                    typeField = DataType::Text;
                rowField->SetName(reinterpret_cast<const char*>(nameField));
                rowField->SetType(typeField);
                result.push_back(rowField );
            }
        }
        sqlite3_finalize(stmt);
    } else {
        std::cout<<"Error: %s\n  "<<sqlite3_errmsg(ppDb);
    }
    return result;
}

}
