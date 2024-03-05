// Step 1: clone repo from https://github.com/google/googletest.git
// Compile your code using "g++ test_hello_world.cpp -lgtest -lgtest_main -pthread --std=c++14"

#include<iostream>
#include<gtest/gtest.h>
using namespace std;

TEST(TestName, Subtest_1){
    ASSERT_FALSE(1==2);
}
TEST(TestName, Subtest_2){
    ASSERT_TRUE(1==1);
}
TEST(TestName, Subtest_3){
    ASSERT_EQ(1, 1);
    cout << " This line will not be executed\n";
}
TEST(TestName, Subtest_4){
    EXPECT_EQ(1, 2);
    cout << " This line will be executed\n";
}

// Assertions can be of three types: Success, Non-Fatal Failure, Fatal Failure
// Fatal assertions, code below assertions doesn't execute. This is not same for non-fatal assertions
// To use non-fatal failure, use EXPECT_ in place of ASSERT_.

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}