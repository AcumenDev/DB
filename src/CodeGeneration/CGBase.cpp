#include "CGBase.h"
namespace CG {
void CGBase::SetDBModel(DBEntity::DBModel dbModel) {
    this->_dbModel = dbModel;
}


CGBase::CGBase() {
    this->_Setting=Core::Settings::GetSettings();
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
