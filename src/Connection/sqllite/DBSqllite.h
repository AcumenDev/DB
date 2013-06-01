#ifndef DBSQLLITE_H
#define DBSQLLITE_H
#include "../DBBase.h"
namespace DB {
class DBSqllite : public  DBBase {
public:
    DBSqllite();

    void Close();

    void Connect();
    std::vector<std::string> GetTables();
    virtual ~DBSqllite();
protected:
private:
};
}
#endif // DBSQLLITE_H
