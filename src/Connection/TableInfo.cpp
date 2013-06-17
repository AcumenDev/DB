#include "./TableInfo.h"

namespace DB {

std::string DataTypeEnumToString(Core::DataType type) {

    switch(type) {
    case Core::DataType::Number: {
        return "Number";
        break;
    }
    case Core::DataType::Text: {
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

void TableInfo::SetType(Core::DataType type) {
    Type = type;
}

std::string TableInfo::GetTypeStr() const {
    return DataTypeEnumToString(Type);
}
Core::DataType TableInfo::GetType() const {
    return Type;
}

std::string TableInfo::GetName() const {
    return Name;
}
}//end namespace DB
