#include "DBConnection.h"
namespace Connection {
DBConnection::DBConnection() {
    //ctor
}

DBConnection::~DBConnection() {
    //dtor
}

std::shared_ptr<DB::DBBase> DBConnection::GetConnection(DB::DBType dbType)  {
    using namespace DB;
    std::shared_ptr<DBBase> result = nullptr;

    switch (dbType) {
    case DBType::Sqllite : {

        result = std::shared_ptr<DBBase> (new DBSqllite());
        break;
    }
    case DBType::Mysql : {
        result = std::shared_ptr<DBBase> (new DBMySql());
        break;
    }
    case DBType::Postgres : {
        throw  Tools::Exception::NotImplementedException();
        break;
    }
    }
    return result;
}

}
