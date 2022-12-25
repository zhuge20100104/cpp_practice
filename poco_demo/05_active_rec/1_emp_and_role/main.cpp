#include "Poco/ActiveRecord/Context.h"
#include "Poco/ActiveRecord/Query.h"
#include "Poco/Data/SQLite/Connector.h"
#include "Poco/Data/Statement.h"
#include "Poco/UUIDGenerator.h"
#include "Sample/Employee.h"
#include "Sample/Role.h"
#include "gtest/gtest.h"


using namespace std::string_literals;
using namespace Poco::Data::Keywords;
using Poco::ActiveRecord::Context;
using Poco::ActiveRecord::Query;
using Sample::Employee;
using Sample::Role;


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    int ret = RUN_ALL_TESTS();
    return ret;
}

class SQLiteTestSuites: public testing::Test {
public:
    static void SetUpTestCase(){
        Poco::Data::SQLite::Connector::registerConnector();
    }
    
    static void TearDownTestCase(){
        Poco::Data::SQLite::Connector::unregisterConnector();
    }

    static std::string s_connect;
    static std::string s_db;
};

std::string SQLiteTestSuites::s_connect = "SQLite";
std::string SQLiteTestSuites::s_db = "data.sqlite";

TEST_F(SQLiteTestSuites, TestCreateTable) {
    Poco::Data::Session session(s_connect, s_db);

	session << "DROP TABLE IF EXISTS employees", now;
	session << "DROP TABLE IF EXISTS roles", now;
	session
		<< "CREATE TABLE employees ("
		<< "  id CHAR(36),"
		<< "  name VARCHAR(64),"
		<< "  ssn VARCHAR(32),"
		<< "  role INTEGER,"
		<< "  manager CHAR(36)"
		<< ")",
		now;
	session
		<< "CREATE TABLE roles ("
		<< "  id INTEGER PRIMARY KEY AUTOINCREMENT,"
		<< "  name VARCHAR(64),"
		<< "  description VARCHAR(256)"
		<< ")",
		now;
}

TEST_F(SQLiteTestSuites, TestInsert) {
    Poco::Data::Session session(s_connect, s_db);
	Context::Ptr pContext = new Context(session);

	Role::Ptr pDeveloper = new Role;
	pDeveloper->name("Developer").description("Developer role");

	ASSERT_TRUE(!pDeveloper->isValid());

	pDeveloper->create(pContext);

	ASSERT_TRUE (pDeveloper->isValid());

	int n = 0;
	session << "SELECT COUNT(*) FROM roles", into(n), now;
	ASSERT_TRUE (n == 1);

	ASSERT_TRUE(pDeveloper->id() == 1);

	Role::Ptr pSeniorDeveloper = new Role;
	pSeniorDeveloper->name("Senior Developer").description("Senior developer role");

	pSeniorDeveloper->create(pContext);

	session << "SELECT COUNT(*) FROM roles", into(n), now;
	ASSERT_TRUE (n == 2);

	ASSERT_TRUE (pSeniorDeveloper->id() == 2);
}