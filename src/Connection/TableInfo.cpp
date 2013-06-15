#include "./TableInfo.h"

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

void TableInfo::SetName(std::string name) {
    Name = name;
}

void TableInfo::SetType(DataType type) {
    Type = type;
}

std::string TableInfo::GetTypeStr() const {
    return DataTypeEnumToString(Type);
}
DataType TableInfo::GetType() const {
    return Type;
}

std::string TableInfo::GetName() const {
    return Name;
}
}//end namespace DB
