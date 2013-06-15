#include "CGBase.h"

namespace CG {
void CGBase::SetDBModel(DBEntity::DBModel dbModel) {
    this->_dbModel = dbModel;
}

CGBase::CGBase() {
    this->_Setting=Core::Settings::GetSettings();
    this->_Log =  LoggingSystem::GetLoggingSystem();
}

void CGBase::Generate() {
    GenerateTables();
    GenerateViews();
    GenerateStoredProcedures();
}
}//end namespace CG
