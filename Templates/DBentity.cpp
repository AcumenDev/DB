#include "DBEntityTestDB.h"

DBEntityTestDB::DBEntityTestDB(std::string patch,  std::string password) {
    status =  sqlite3_open(patch.c_str(),&_Db);
    if(status==0) {
        Test1.SetDBContext(_Db);
    }
}

DBEntityTestDB::~DBEntityTestDB() {
    sqlite3_close(_Db);
}
