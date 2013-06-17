#ifndef TABLEINFO_H
#define TABLEINFO_H

#include "../tools/DefDB.h"
namespace DB {
class TableInfo {
public:
    TableInfo() {};
    virtual ~TableInfo() {};
    void SetName(std::string name);
    void SetType(Core::DataType type);
    std::string GetTypeStr() const;
    Core::DataType GetType() const;
    std::string GetName() const;
protected:
private:
    std::string Name;
    Core::DataType Type;
};
}//end namespace DB
#endif // TABLEINFO_H
