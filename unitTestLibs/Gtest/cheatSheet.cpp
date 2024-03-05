//writing basic testcases:
TEST(TestCaseName, TestName) {
    // Arrange: Setup test data and objects
    // Act: Perform the action or method being tested
    // Assert: Verify the result and state
    ASSERT_EQ(expected_value, actual_value);
    ASSERT_NE(val1, val2);
    ASSERT_TRUE(condition);
    ASSERT_FALSE(condition);


    // For string types: both ASSERT & EXPECT
    ASSERT_STREQ(str1, str2);
    ASSERT_STRNE(str1, str2);

    //ignore case versions for string types:
    ASSERT_STRCASEEQ(str1, str2);
    ASSERT_STRCASENE(str1, str2);
}


// test Fixtures:
class FixtureName : public ::testing::Test {
protected:
    void SetUp() override {
        // Code to run before each test
    }

    void TearDown() override {
        // Code to run after each test
    }

    // Declare member variables accessible by tests
};

TEST_F(FixtureName, TestName) {
    // Test code can access members of FixtureName
}


/*
Running Tests:
    Compile your test file with Google Test linked.
    Run the executable.
    You can filter tests using --gtest_filter=TestSuiteName.TestName.
*/

/*
Assertions:
    ASSERT_*: Terminates the test if the assertion fails.
    EXPECT_*: Allows the test to continue even if the assertion fails.
*/

/*
Matchers:
// Some commonly used matchers
    EXPECT_THAT(container, Contains(element));
    EXPECT_THAT(container, Not(Contains(element)));
    EXPECT_THAT(actual_value, MatcherType(expected_value));
*/

// Mocking:
class MockClassName : public ClassName {
public:
    MOCK_METHOD(returnType, methodName, (parameterTypes), (override));
};



//verifying Mocks:
using ::testing::_;
using ::testing::Return;

MockClassName mockObj;
EXPECT_CALL(mockObj, methodName(_))
    .WillOnce(Return(expected_value));



//Test Annotations:
// Disabled test
TEST(TestCaseName, TestName) {
    // Test code
}
// Add DISABLED_ before TEST to disable a test.




// Value parameterised tests:
INSTANTIATE_TEST_SUITE_P(TestSuiteName,
                         TestFixtureName,
                         ::testing::Values(val1, val2, val3));


//Type parameterised tests:

template <typename T>
class TypeName : public ::testing::Test {
    // Test code
};

using MyTypes = ::testing::Types<Type1, Type2>;
TYPED_TEST_SUITE(TypeName, MyTypes);





