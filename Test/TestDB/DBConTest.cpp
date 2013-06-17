#include "gtest/gtest.h"
#include "Connection/DBConnection.h"

namespace {
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

TEST(Connection, GetDBName) {
    std::shared_ptr<DBBase> dbSqlLite = DBConnection::GetConnection(DBType::Sqllite);
    ASSERT_NO_THROW(dbSqlLite->Connect("../../TestDB.db","",""));
    std::string testName = dbSqlLite->GetDBName();
    EXPECT_NE(testName.length(),0 );
}

TEST(Connection, GetTables) {
    std::shared_ptr<DBBase> dbSqlLite = DBConnection::GetConnection(DBType::Sqllite);
    ASSERT_NO_THROW(dbSqlLite->Connect("../../TestDB.db","",""));
    std::vector<std::string> dbTables =  dbSqlLite->GetTables();
    int lenght =  dbTables.size();
    EXPECT_NE(lenght, 0);
}

TEST(Connection, GetTableInfo) {
    std::shared_ptr<DBBase> dbSqlLite = DBConnection::GetConnection(DBType::Sqllite);
    ASSERT_NO_THROW(dbSqlLite->Connect("../../TestDB.db","",""));
    std::vector<std::string> dbTables =  dbSqlLite->GetTables();
    for(const auto& itemTableName:dbTables) {
        int lenght =  dbSqlLite->GetTableInfo(itemTableName).size();
        EXPECT_NE(lenght, 0);

    }
}











//class QueueTest : public ::testing::Test {
// protected:
//  virtual void GetConnection() {
//    dbSqlLite = DBConnection::GetConnection(DBType::Sqllite);
//  }
//
//  // virtual void TearDown() {}
//
// std::shared_ptr<DBBase> dbSqlLite;
//};






}
