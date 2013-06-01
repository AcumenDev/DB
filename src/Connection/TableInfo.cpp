#include "TableInfo.h"
namespace DB {


std::string DataTypeEnumToString(DataType type) {

    switch(type) {
    case DataType::Number: {
        return "Number";
        break;
    }
    case DataType::Text: {
        return "Text";
        break;
    }
    default: {
        return "Unknown Type";
    }
    }
}




TableInfo::TableInfo() {
    //ctor
}

TableInfo::~TableInfo() {
    //dtor
}

void TableInfo::SetName(std::string name) {
    Name = name;
}

void TableInfo::SetType(DataType type) {
    Type = type;
}

std::string TableInfo::GetTypeStr() {
    return DataTypeEnumToString(Type);
}
DataType TableInfo::GetType() {
    return Type;
}

std::string TableInfo::GetName() {
    return Name;
}



}
