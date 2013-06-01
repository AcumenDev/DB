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
std::string DBSqllite::GetDBName()
{
return "";
}

void DBSqllite::Connect(std::string patch, std::string login, std::string password) {
    status =  sqlite3_open(patch.c_str(),&ppDb);
}

std::vector<std::string> DBSqllite::GetTables() {

//    LoggingSystem * Log = LoggingSystem::GetLoggingSystem();
    std::vector<std::string> vectorResult;
//    char * errorMsg[1024];
//    if(0==status) {
//        status =  sqlite3_exec(ppDb,GET_TABLES_QUERY.c_str(),
//        [&] (void *data, int coln, char **rows, char **colnm) -> int {
//            for(int i = 0; i < coln; i++)
//                std::cout<<colnm[i]<<" ";
// std::cout<<std::endl;
//            for(int i = 0; i < coln; i++)
//                std::cout<<rows[i]<<" ";
//
//            return 0;
//        },
//        &vectorResult,
//        errorMsg);
//    }




    char  *pSQL2;
    sqlite3_stmt *stmt;
    int rc;
    rc = sqlite3_prepare_v2(ppDb, GET_TABLES_QUERY.c_str(), -1, &stmt, (const char**)&pSQL2);
    if (rc == SQLITE_OK) {
        int nCols = sqlite3_column_count(stmt);
        if (nCols) {
//            int nCol;
           // for (nCol = 0; nCol < nCols; nCol++)
           //     std::cout<<sqlite3_column_name(stmt, nCol)<<" ";
          //  std::cout<<std::endl;
            while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
                // for (nCol = 0; nCol < nCols; nCol++)
                //     std::cout<<sqlite3_column_text(stmt, nCol)<<" ";
                auto nameTable = sqlite3_column_text(stmt, 1);
              //  std::cout<<nameTable<<std::endl;
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

std::vector<TableInfo> DBSqllite::GetTableInfo(std::string tableName)
{
    std::vector<TableInfo> result;
char  *pSQL2;
    sqlite3_stmt *stmt;
    int rc;
    rc = sqlite3_prepare_v2(ppDb, GET_TABLES_QUERY.c_str(), -1, &stmt, (const char**)&pSQL2);
    if (rc == SQLITE_OK) {
        int nCols = sqlite3_column_count(stmt);
        if (nCols) {
            int nCol;
            for (nCol = 0; nCol < nCols; nCol++)
                std::cout<<sqlite3_column_name(stmt, nCol)<<" ";
            std::cout<<std::endl;
            while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
                 for (nCol = 0; nCol < nCols; nCol++)
                     std::cout<<sqlite3_column_text(stmt, nCol)<<" ";
                auto nameTable = sqlite3_column_text(stmt, 1);
                std::cout<<nameTable<<std::endl;
             //   vectorResult.push_back(reinterpret_cast<const char*>(nameTable));

            }
            std::cout<<std::endl;
        }
        sqlite3_finalize(stmt);
    } else {
        std::cout<<"Error: %s\n  "<<sqlite3_errmsg(ppDb);
    }
    return result;
}

}
