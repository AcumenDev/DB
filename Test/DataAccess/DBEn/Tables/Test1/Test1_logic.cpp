#include "Test1_logic.h"

void Test1_logic::SetDBContext(sqlite3* ppDb) {
    this->_Db = ppDb;
}



std::vector<Test1> Test1_logic::GetList() {
    const std::string GET_DATA_TABLE = "select id, name from test1";
    return ExecutionSelect(GET_DATA_TABLE);
}

std::vector<Test1> Test1_logic::GetList(int startPos, int count) {
    std::vector<Test1> vectorResult;
    const std::string GET_DATA_TABLE = "SELECT id, name FROM test1 LIMIT "+std::to_string(startPos)+", "+std::to_string(count);
    if(count==0) return vectorResult;
    return ExecutionSelect(GET_DATA_TABLE);
}


bool Test1_logic::InsertList( const std::vector<Test1> listVal) {
    if(listVal.empty()) return false;
    std::string insertDataTableSQL = "INSERT INTO test1 (id, name) VALUES ";
    std::string values;
    for(const auto& item:listVal) {
        values+="("+std::to_string(item.Id)+",'"+ item.Name+"'),";
    }

    values = values.substr(0,values.length()-1);

    insertDataTableSQL+=values;
    std::cout<<insertDataTableSQL<<std::endl;
    char  *pSQL2;
    sqlite3_stmt *stmt;
    _Status = sqlite3_prepare_v2(_Db, insertDataTableSQL.c_str(), -1, &stmt, (const char**)&pSQL2);
    _Status = sqlite3_step(stmt);
    if (_Status == SQLITE_OK || _Status ==SQLITE_DONE) {
        sqlite3_finalize(stmt);
        std::cout<<"OK"<<std::endl;
    } else {
        std::cout<<"Error: "+std::string(sqlite3_errmsg(_Db))+" \n  ";
        return false;
    }
    return true;
}


bool Test1_logic::Insert(Test1 value) {
    std::vector<Test1> values;
    values.push_back(value);
    return InsertList(values);
}

std::vector<Test1> Test1_logic::ExecutionSelect(std::string query) {
    std::vector<Test1> vectorResult;
    char  *pSQL2;
    sqlite3_stmt *stmt;
    int rc;
    rc = sqlite3_prepare_v2(_Db, query.c_str(), -1, &stmt, (const char**)&pSQL2);
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

