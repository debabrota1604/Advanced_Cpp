#include<iostream>
#include<gtest/gtest.h>
using namespace std;
// Unit tests comprises of three stages: Arrange, Act, Assert

TEST(TestName, Incr_by_5){
    //Arrange: 
    int val = 100;
    int incr = 5;

    //Act:
    val = val + incr;

    //Assert:
    ASSERT_EQ(val, 105);
}
TEST(TestName, Incr_by_10){
    //Arrange: 
    int val = 100;
    int incr = 10;

    //Act:
    val = val + incr;

    //Assert:
    ASSERT_EQ(val, 110);
}



int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}