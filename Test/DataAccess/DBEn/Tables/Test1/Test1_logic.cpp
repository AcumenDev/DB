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
                test1.Id =   sqlite3_column_int(stmt, 0);
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

std::vector<Test1> Test1_logic::GetList(int startPos, int count) {
    const std::string GET_DATA_TABLE = "SELECT id, name FROM test1 LIMIT "+std::to_string(startPos)+", "+std::to_string(count);

// TODO (akum#1#): Убрать дублирование


    std::vector<Test1> vectorResult;
    char  *pSQL2;
    sqlite3_stmt *stmt;
    int rc;
    rc = sqlite3_prepare_v2(_Db, GET_DATA_TABLE.c_str(), -1, &stmt, (const char**)&pSQL2);
    if (rc == SQLITE_OK) {
        if (sqlite3_column_count(stmt)) {
            while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
                Test1 test1;
                test1.Id =   sqlite3_column_int(stmt, 0);
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

std::vector<Test1> Test1_logic::InsertList( const std::vector<Test1> listVal) {
    std::string insertDataTableSQL = "INSERT INTO test1 (id, name) VALUES ";
    std::string values;
    for(const auto& item:listVal) {
        values+="("+std::to_string(item.Id)+",'"+ item.Name+"')";
    }
    insertDataTableSQL+=values;


    std::cout<<insertDataTableSQL<<std::endl;


    char  *pSQL2;
    sqlite3_stmt *stmt;
    _Status = sqlite3_prepare_v2(_Db, insertDataTableSQL.c_str(), -1, &stmt, (const char**)&pSQL2);
    if (_Status == SQLITE_OK) {
        sqlite3_finalize(stmt);
        std::cout<<"OK"<<std::endl;
    } else {
        std::cout<<"Error: %s\n  "<<sqlite3_errmsg(_Db);
    }

    std::string create_table ="create table ";
     //char  *pSQL2;
    sqlite3_stmt *stmt1;
    _Status = sqlite3_prepare_v2(_Db, create_table.c_str(), -1, &stmt1, (const char**)&pSQL2);
    if (_Status == SQLITE_OK) {
        sqlite3_finalize(stmt);
        std::cout<<"OK"<<std::endl;
    } else {
        std::cout<<"Error: %s\n  "<<sqlite3_errmsg(_Db);
    }



    return listVal;
}
