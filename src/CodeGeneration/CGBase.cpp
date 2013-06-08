#include "CGBase.h"
namespace CG {
void CGBase::SetDBModel(DBEntity::DBModel dbModel) {
    this->_dbModel = dbModel;
}


CGBase::CGBase() {
    //ctor
}

CGBase::~CGBase() {
    //dtor
}
void CGBase::Generate() {
    GenerateTables();
    GenerateViews();
    GenerateStoredProcedures();
}


}
