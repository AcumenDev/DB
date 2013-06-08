#ifndef CGBASE_H
#define CGBASE_H
#include "../DBEntity/DBModel.h"
#include "../tools/Settings.h"
namespace CG {

class CGBase {
public:
    CGBase();
    virtual ~CGBase();
    void SetDBModel(DBEntity::DBModel dbModel ) ;
    virtual void Generate();
    virtual void GenerateTables() = 0;
    virtual void GenerateViews() = 0;
    virtual void GenerateStoredProcedures() = 0;

protected:
    DBEntity::DBModel _dbModel;
    std::shared_ptr<Core::Settings> _Setting;
private:
};
}
#endif // CGBASE_H
