#ifndef DEFDB_H_INCLUDED
#define DEFDB_H_INCLUDED

namespace DB {
enum DBType {
    Sqllite,
    Mysql,
    Postgres
};

enum DataType
{
    Number,
    String
};


}



#endif // DEFDB_H_INCLUDED
