#include "CGBase.h"

namespace CG {
void CGBase::SetDBModel(DBEntity::DBModel dbModel) {
    this->_dbModel = dbModel;
}

CGBase::CGBase():
    _Setting(Core::Settings::GetSettings()),
    _Log(Tools::LoggingSystem::GetLoggingSystem()) {}

void CGBase::Generate() {
    GenerateTables();
    GenerateViews();
    GenerateStoredProcedures();
}
}//end namespace CG
