#ifndef CGBASE_H
#define CGBASE_H
#include "../DBModel/DBModel.h"
namespace CG {

class CGBase {
public:
    CGBase();
    virtual ~CGBase();
    void SetDBModel(DBModel::DBModel dbModel ) ;
    virtual void GenerateTables() = 0;
   // virtual void GenerateViews() = 0;
  //  virtual void GenerateStoredProcedures() = 0;


//        void SaveToFile(std::string patch, std::string content);

protected:
    DBModel::DBModel _dbModel;
private:
};
}
#endif // CGBASE_H
