#include <[[NAME_TABLE]]Logic.h>

[[NAME_TABLE]]Logic::[[NAME_TABLE]]Logic(){

}

[[NAME_TABLE]]Logic::~[[NAME_TABLE]]Logic(){

}
void test1Logic::SetDBContext(sqlite3* ppDb) {
	this->_Db = ppDb;
}

std::vector<[[NAME_TABLE]]> [[NAME_TABLE]]Logic::GetList() {
	const std::string GET_DATA_TABLE = "select id, name from [[NAME_TABLE]]";
	std::vector<[[NAME_TABLE]]> vectorResult;
	char  *pSQL2;
	sqlite3_stmt *stmt;
	int rc;
	rc = sqlite3_prepare_v2(_Db, GET_DATA_TABLE.c_str(), -1, &stmt, (const char**)&pSQL2);
	if (rc == SQLITE_OK) {
		if (sqlite3_column_count(stmt)) {
			while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
				[[NAME_TABLE]] [[NAME_TABLE]]_;
[[BODY]]
				vectorResult.push_back([[NAME_TABLE]]_);
			}
		}
	sqlite3_finalize(stmt);
	} else {
	std::cout<<"Error: %s\n  "<<sqlite3_errmsg(_Db);
	}
return vectorResult;
}
