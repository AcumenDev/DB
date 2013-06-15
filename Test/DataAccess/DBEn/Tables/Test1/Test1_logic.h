#ifndef TEST1_LOGIC_H
#define TEST1_LOGIC_H
#include <vector>
#include "test1.h"
#include "sqlite3.h"

class Test1_logic {
public:
    Test1_logic();
    virtual ~Test1_logic();
    void SetDBContext(sqlite3 * ppDb);
    Test1_logic(const Test1_logic&) = delete;
    std::vector<Test1> GetList();
    std::vector<Test1> GetList(int startPos, int count);
    std::vector<Test1> InsertList(std::vector<Test1> listVal);
protected:
private:
    sqlite3 *_Db  ;
    int _Status ;

};

#endif // TEST1_LOGIC_H
