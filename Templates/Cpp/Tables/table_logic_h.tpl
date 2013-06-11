#ifndef test1Logic_H
#define test1Logic_H
#include <test1.h>
class test1Logic {
	test1Logic();
	virtual ~test1Logic();
	test1Logic Test1_logic(const test1Logic&) = delete;
	void SetDBContext(sqlite3 * ppDb);
	std::vector<test1> GetList();
private:
	sqlite3 *_Db;
	int _Status ;
}
#endif