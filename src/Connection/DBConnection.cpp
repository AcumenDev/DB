#include "DBConnection.h"
namespace Connection {
DBConnection::DBConnection() {
    //ctor
}

DBConnection::~DBConnection() {
    //dtor
}

DB::DBBase * DBConnection::GetConnection(DB::DBType dbType) {
    using namespace DB;
    DBBase * result = nullptr;

    switch (dbType) {
    case DBType::Sqllite :{
            result = new DBSqllite();
            break;
        }
    case DBType::Mysql :{
            result = new DBMySql();
            break;
        }
    case DBType::Postgres :{
            throw  Tools::NotImplementedException();
            break;
        }
    }
    return result;
}

}
