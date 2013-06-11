#ifndef [[NAME_TABLE]]Logic_H
#define [[NAME_TABLE]]Logic_H
#include <[[NAME_TABLE]].h>
class [[NAME_TABLE]]Logic {
	[[NAME_TABLE]]Logic();
	virtual ~[[NAME_TABLE]]Logic();
	[[NAME_TABLE]]Logic [[NAME_TABLE]]Logic(const [[NAME_TABLE]]Logic&) = delete;
	void SetDBContext(sqlite3 * ppDb);
	std::vector<[[NAME_TABLE]]> GetList();
private:
	sqlite3 *_Db;
	int _Status ;
}
#endif
