#include <test1Logic.h>
test1Logic::test1Logic(){
}
test1Logic::~test1Logic(){
}
void test1Logic::SetDBContext(sqlite3* ppDb) {
	this->_Db = ppDb;
}
std::vector<test1> test1Logic::GetList() {
	const std::string GET_DATA_TABLE = "select id, name from test1";
	std::vector<test1> vectorResult;
	char  *pSQL2;
	sqlite3_stmt *stmt;
	int rc;
	rc = sqlite3_prepare_v2(_Db, GET_DATA_TABLE.c_str(), -1, &stmt, (const char**)&pSQL2);
	if (rc == SQLITE_OK) {
		if (sqlite3_column_count(stmt)) {
			while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
				test1 test1_;
				test1_.id = sqlite3_column_int(stmt, 0);
				test1_.name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
				vectorResult.push_back(test1_.);
			}
		}
	sqlite3_finalize(stmt);
	} else {
	std::cout<<"Error: %s\n  "<<sqlite3_errmsg(_Db);
	}
return vectorResult;
}