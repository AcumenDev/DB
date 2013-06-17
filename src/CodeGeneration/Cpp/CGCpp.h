#ifndef CGCPP_H
#define CGCPP_H
#include "../CGBase.h"
#include "../../Tools/FileSystem.h"

namespace CG {
class CGCpp : public  CGBase {
public:
    CGCpp() {};
    virtual ~CGCpp() {};
    void GenerateTablesLogic( const DBEntity::DBTable& dbTable,std::string path);
    void GenerateTablesStruct(const DBEntity::DBTable& dbTable,std::string path);
    void GenerateTables() override;
    void GenerateViews() override;
    void GenerateStoredProcedures() override;
    void GenerateExternalFiles() override;
    void Generate() override;
    void CopyLib();
protected:

private:
};
}
#endif // CGCPP_H
