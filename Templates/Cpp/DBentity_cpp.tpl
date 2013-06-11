#include "DBEntity[[DB_NAME]].h"

DBEntity[[DB_NAME]]::DBEntity[[DB_NAME]](std::string path,  std::string password) {
    status =  sqlite3_open(path.c_str(),&_Db);
    if(status==0) {
        [[SET_DBCONTEXT_BLOCK]]
    }
}

DBEntity[[DB_NAME]]::~DBEntity[[DB_NAME]]() {
    sqlite3_close(_Db);
}
