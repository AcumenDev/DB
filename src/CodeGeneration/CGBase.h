#ifndef CGBASE_H
#define CGBASE_H
#include <regex>
#include <iterator>
#include "../DBEntity/DBModel.h"
#include "../Core/Settings.h"
#include "../Tools/TemplateHelper.h"

namespace CG {
class CGBase {
public:
    CGBase();
    virtual ~CGBase() {};
    void SetDBModel(DBEntity::DBModel dbModel ) ;
    virtual void Generate();
    virtual void GenerateTables() = 0;
    virtual void GenerateViews() = 0;
    virtual void GenerateStoredProcedures() = 0;
    virtual void GenerateExternalFiles() =0;
protected:
    DBEntity::DBModel _dbModel;
    std::shared_ptr<Core::Settings> _Setting;
    std::shared_ptr<Tools::LoggingSystem> _Log;
private:
};
}//end namespace CG
#endif // CGBASE_H
