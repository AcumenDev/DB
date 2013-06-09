#include "Test1_logic.h"

Test1_logic::Test1_logic() {
    //ctor
}

Test1_logic::~Test1_logic() {
    //dtor
}
void Test1_logic::SetDBContext(sqlite3* ppDb) {
    this->_Db = ppDb;
}

std::vector<Test1> Test1_logic::GetList() {
    const std::string GET_DATA_TABLE = "select id, name from test1";

    std::vector<Test1> vectorResult;
    char  *pSQL2;
    sqlite3_stmt *stmt;
    int rc;
    rc = sqlite3_prepare_v2(_Db, GET_DATA_TABLE.c_str(), -1, &stmt, (const char**)&pSQL2);
    if (rc == SQLITE_OK) {
        if (sqlite3_column_count(stmt)) {
            while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
                Test1 test1;
                test1.Id =   sqlite3_column_int(stmt, 0);;
                test1.Name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
                vectorResult.push_back(test1);
            }
            std::cout<<std::endl;
        }
        sqlite3_finalize(stmt);
    } else {
        std::cout<<"Error: %s\n  "<<sqlite3_errmsg(_Db);
    }
    return vectorResult;
}
