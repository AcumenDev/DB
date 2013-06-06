#include "DBTableColumn.h"

DBTableColumn::DBTableColumn(std::string name, std::string type)
{
    //ctor
    this->Name=name;
    this->Type=type;
}

DBTableColumn::~DBTableColumn()
{
    //dtor
}
