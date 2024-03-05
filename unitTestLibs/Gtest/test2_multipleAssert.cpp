#include<iostream>
#include<gtest/gtest.h>
using namespace std;

// Multiple Expects in a single testcase: If one fails, whole test fails and you don't know which assert/expect failed.


TEST(TestName, Subtest_1){
    ASSERT_FALSE(1==2);
    EXPECT_EQ(1, 2); // If assert fails, expect wont execute
}
TEST(TestName, Subtest_2){
    EXPECT_FALSE(1==1); //Dont know from the output which expect threw error
    EXPECT_TRUE(1==1);
}



int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}