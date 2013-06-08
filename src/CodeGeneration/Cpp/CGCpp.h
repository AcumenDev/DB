#ifndef CGCPP_H
#define CGCPP_H
#include "../CGBase.h"
#include "../../tools/FileSystem.h"

namespace CG {
class CGCpp : public  CGBase {
public:
    CGCpp();
    virtual ~CGCpp();
    void GenerateTablesLogic(DBEntity::DBTable dbTable);
    void GenerateTablesStruct(DBEntity::DBTable dbTable);
    void GenerateTables() override;
    void GenerateViews() override;
    void GenerateStoredProcedures() override;


protected:
private:
};
}
#endif // CGCPP_H
