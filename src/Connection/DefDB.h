#ifndef DEFDB_H_INCLUDED
#define DEFDB_H_INCLUDED
#include <iostream>

namespace DB {
enum DBType {
    Sqllite,
    Mysql,
    Postgres
};

enum DataType {
    Number,
    Text
};
} //end namespace DB
#endif // DEFDB_H_INCLUDED
