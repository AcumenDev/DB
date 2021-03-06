#include "DBSqllite.h"

namespace DB {

DBSqllite::~DBSqllite() {
}

void DBSqllite::Close() {
    if(nullptr!= ppDb)
        sqlite3_close_v2(ppDb);
}
std::string DBSqllite::GetDBName() const {
    return _NameDB;
}

void DBSqllite::Connect(std::string path, std::string login, std::string password) {

    unsigned found = path.find_last_of("/\\");
    unsigned foundDot = path.find_last_of(".");
    _NameDB = path.substr(found+1,foundDot);

    _Log->Write(("Connect to sqllite : "+path));
    status =  sqlite3_open(path.c_str(),&ppDb);
    if(SQLITE_OK!=status) {
        throw  Tools::Exception::NotOpenDataBase();
    }
}

std::vector<std::string> DBSqllite::GetTables() const {
    std::vector<std::string> vectorResult;
    char  *pSQL2;
    sqlite3_stmt *stmt;
    sqlite_int64 rc;
    rc = sqlite3_prepare_v2(ppDb, GET_TABLES_QUERY.c_str(), -1, &stmt, (const char**)&pSQL2);
    if (SQLITE_OK==rc) {
        if (sqlite3_column_count(stmt)) {
            while (sqlite3_step(stmt) == SQLITE_ROW) {
                auto nameTable = sqlite3_column_text(stmt, 1);
                vectorResult.push_back(reinterpret_cast<const char*>(nameTable));
            }
        }
        sqlite3_finalize(stmt);
    } else {
        _Log->Write(("Error: "+std::string(sqlite3_errmsg(ppDb))),Tools::LogType::Error);
    }
    return vectorResult;
}

std::vector<std::shared_ptr<TableInfo>> DBSqllite::GetTableInfo(std::string tableName) const {
    std::string  getTableInfoQuery ="PRAGMA table_info( '"+ tableName +"' );";
    std::vector<std::shared_ptr<TableInfo>> result;
    char  *pSQL2;
    sqlite3_stmt *stmt;
    sqlite_int64 rc;
    rc = sqlite3_prepare_v2(ppDb, getTableInfoQuery.c_str(), -1, &stmt, (const char**)&pSQL2);
    if (SQLITE_OK==rc ) {
        if (sqlite3_column_count(stmt)) {
            while (sqlite3_step(stmt) == SQLITE_ROW) {
                auto nameField = sqlite3_column_text(stmt, 1);
                std::shared_ptr<TableInfo> rowField(new TableInfo());
                Core::DataType typeField = Core::DataType::Text;
                std::string fieldTypeRaw = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
                if("NUMERIC"==fieldTypeRaw )
                    typeField = Core::DataType::Number;
                if("TEXT"==fieldTypeRaw)
                    typeField = Core::DataType::Text;
                rowField->SetName(reinterpret_cast<const char*>(nameField));
                rowField->SetType(typeField);
                result.push_back(rowField );
            }
        }
        sqlite3_finalize(stmt);
    } else {
        _Log->Write(("Error: "+std::string(sqlite3_errmsg(ppDb))),Tools::LogType::Error);
    }
    return result;
}
} //end namespace DB
