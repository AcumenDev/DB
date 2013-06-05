#ifndef TABLEINFO_H
#define TABLEINFO_H

#include "DefDB.h"
namespace DB {
class TableInfo {
public:
    TableInfo();
    virtual ~TableInfo();
    void SetName(std::string name);
    void SetType(DataType type);
    std::string GetTypeStr() const;
    DataType GetType() const;
    std::string GetName() const;
protected:
private:
    std::string Name;
    DataType Type;
};
}
#endif // TABLEINFO_H
