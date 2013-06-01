#include "DBSqllite.h"
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
std::string DBSqllite::GetDBName() {
    return "";
}

void DBSqllite::Connect(std::string patch, std::string login, std::string password) {
    status =  sqlite3_open(patch.c_str(),&ppDb);
}

std::vector<std::string> DBSqllite::GetTables() {
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

std::vector<TableInfo *> DBSqllite::GetTableInfo(std::string tableName) {
    std::string  getTableInfoQuery ="PRAGMA table_info( '"+ tableName +"' );";
    std::vector<TableInfo *> result;
    char  *pSQL2;
    sqlite3_stmt *stmt;
    int rc;
    rc = sqlite3_prepare_v2(ppDb, getTableInfoQuery.c_str(), -1, &stmt, (const char**)&pSQL2);
    if (rc == SQLITE_OK) {
        if (sqlite3_column_count(stmt)) {
            while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
                auto nameFild = sqlite3_column_text(stmt, 1);
                auto rowFild = new TableInfo();
                DataType typeFild;
                std::string fildTypeRaw = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
                if("NUMERIC"==fildTypeRaw )
                    typeFild = DataType::Number;
                if("TEXT"==fildTypeRaw)
                    typeFild = DataType::Text;
                rowFild->SetName(reinterpret_cast<const char*>(nameFild));
                rowFild->SetType(typeFild);
                result.push_back(rowFild );
            }
        }
        sqlite3_finalize(stmt);
    } else {
        std::cout<<"Error: %s\n  "<<sqlite3_errmsg(ppDb);
    }
    return result;
}

}
