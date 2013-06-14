#ifndef CGCPP_H
#define CGCPP_H
#include "../CGBase.h"
#include "../../tools/FileSystem.h"

namespace CG {
class CGCpp : public  CGBase {
public:
    CGCpp() {};
    virtual ~CGCpp() {};
    void GenerateTablesLogic( const DBEntity::DBTable& dbTable);
    void GenerateTablesStruct(const DBEntity::DBTable& dbTable);
    void GenerateTables() override;
    void GenerateViews() override;
    void GenerateStoredProcedures() override;
    void GenerateExternalFiles() override;
    void Generate() override;
protected:

private:
};
}
#endif // CGCPP_H
