#include "DBConnection.h"

namespace Connection {
std::shared_ptr<DB::DBBase> DBConnection::GetConnection(Core::DBType dbType) {

    std::shared_ptr<DB::DBBase> result = nullptr;

    switch (dbType) {

    case Core::DBType::Sqllite : {
        result = std::shared_ptr<DB::DBBase> (new DB::DBSqllite());
        break;
    }
    case Core::DBType::Mysql : {
        result = std::shared_ptr<DB::DBBase> (new DB::DBMySql());
        break;
    }
    case Core::DBType::Postgres : {
        throw  Tools::Exception::NotImplementedException();
        break;
    }
    }
    return result;
}
} //end namespace Connection
