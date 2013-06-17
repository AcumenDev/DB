#ifndef DEFINES_H_INCLUDED
#define DEFINES_H_INCLUDED
#include <iostream>

namespace Core {

enum DBType {
    Sqllite,
    Mysql,
    Postgres
};

enum DataType {
    Number,
    Text
};

enum Language {
    Cpp,
    Java
};

} //end namespace DB
#endif // DEFINES_H_INCLUDED
