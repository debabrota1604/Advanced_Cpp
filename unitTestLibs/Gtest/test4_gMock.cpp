#include<iostream>
#include<gtest/gtest.h>
#include<gtest/gmock.h> // required for mocks
using namespace std;

using ::testing::Atleast;
using ::testing::Return;
using ::testing::_;


// Mocks are used for testing the behaviour of APIs or interfaces which will be used in component under test
// https://www.youtube.com/watch?v=dLB2aDasVTg&list=PL_dsdStdDXbo-zApdWB5XiF2aWpsqzV55&index=4

// Assume this is the DB interface
class DbConnect{
    public:
    virtual bool login(string uname, stirng pswd){ return true; }
    virtual bool logout(string uname){ return true; }
    virtual int fetchRecord(){return -1; }
};

// Assume this is the DB implementation
class MyDB{
    DbConnect& dbc;
    public:
    MyDB(DbConnect& _dbc):dbc(_dbc){}
    int Init(string username, string password){
        if(dbc.login(username, password) != true){
            cout << "DB Failure\n";
            return -1;
        }
        else{
            cout << "DB Success\n";
            return 1;
        }
    }
};

// Mock for DbConnect class: extend publicly. Use Mock Macros like this:
class MockDB: public DbConnect{
    public:
    MOCK_METHOD0(fetchRecordm, int());
    MOCK_METHOD1(logout, bool (string username);
    MOCK_METHOD2(login, bool(string username, string password));
}

// Writing testcases:
TEST(MyDbTest, LoginTest){

    // Arrange
    MockDB mdb;
    MyDB db(mdb);

    EXPECT_CALL(mdb, login(""terminator", "I'm Back""))
    .Times(1)
    .WillOnce(Return(false));

    //Act
    int retVal = db.init("terminator", "I'm Back");

    //Assert
    EXPECT_EQ(retVal, 1);


}

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}