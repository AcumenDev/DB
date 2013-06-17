#include <iostream>
#include "gtest/gtest.h"
#include "Connection/DBConnection.h"

namespace
{

using namespace Connection;
using namespace DB;
using namespace Core;
TEST(Connection, GetConnection) {
    std::shared_ptr<DBBase> dbSqlLite = DBConnection::GetConnection(DBType::Sqllite);
    EXPECT_NE(nullptr,dbSqlLite.get());
}



TEST(Connection, Connect) {
    std::shared_ptr<DBBase> dbSqlLite = DBConnection::GetConnection(DBType::Sqllite);
    ASSERT_NO_THROW(dbSqlLite->Connect("../../TestDB.db","",""));
}
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
