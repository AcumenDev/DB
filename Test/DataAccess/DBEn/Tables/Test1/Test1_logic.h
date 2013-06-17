#ifndef TEST1_LOGIC_H
#define TEST1_LOGIC_H
#include <vector>
#include "test1.h"
#include "sqlite3.h"

class Test1_logic {
public:
    Test1_logic() {};
    virtual ~Test1_logic() {};
    void SetDBContext(sqlite3 * ppDb);
    Test1_logic(const Test1_logic&) = delete;
    std::vector<Test1> GetList();
    std::vector<Test1> GetList(int startPos, int count);
    bool InsertList(std::vector<Test1> listVal);
    bool Insert(Test1 value);
protected:
    std::vector<Test1> ExecutionSelect(std::string query);
private:
    sqlite3 *_Db;
    int _Status;
};

#endif // TEST1_LOGIC_H
