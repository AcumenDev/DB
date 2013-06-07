#include "CGBase.h"
namespace CG {
void CGBase::SetDBModel(DBModel::DBModel dbModel)
{
    this->_dbModel = dbModel;
}


CGBase::CGBase() {
    //ctor
}

CGBase::~CGBase() {
    //dtor
}
}
