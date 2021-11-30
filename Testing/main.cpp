#include <gtest/gtest.h>
#include "Tests/brackets.h"
#include "Tests/stack.h"

//True Bracket Sequence testing
TEST(TrueBracketSeqTest, RoundBrackets) {
    ASSERT_TRUE(check_brackets("()"));
    ASSERT_TRUE(check_brackets("(()())"));
    ASSERT_TRUE(check_brackets("()( )(()()) (((()())) ())"));

    ASSERT_FALSE(check_brackets("("));
    ASSERT_FALSE(check_brackets("()(() ))"));
    ASSERT_FALSE(check_brackets("((  )(( )"));
}

TEST(TrueBracketSeqTest, SquareBrackets) {
    ASSERT_TRUE(check_brackets("[ ]"));
    ASSERT_TRUE(check_brackets("[[] []]"));
    ASSERT_TRUE(check_brackets("[][][[ ][][ [] ]]"));

    ASSERT_FALSE(check_brackets("[][ ]][]"));
    ASSERT_FALSE(check_brackets("][][ ]][["));
    ASSERT_FALSE(check_brackets("[][ ][ [][[ ][][ ][][ ]]"));
}

TEST(TrueBracketSeqTest, DifferentBrackets) {
    ASSERT_TRUE(check_brackets("([])"));
    ASSERT_TRUE(check_brackets("()[ ] ([])"));
    ASSERT_TRUE(check_brackets("[[ ] ()] ()(( [[]])[ ])"));
    ASSERT_TRUE(check_brackets(""));

    ASSERT_FALSE(check_brackets("([)]"));
    ASSERT_FALSE(check_brackets("[][][()[]()"));
    ASSERT_FALSE(check_brackets("[[]()() )"));
}

//Stack testing
class ArrayStackFixture : public ::testing::Test {
public:
    virtual ~ArrayStackFixture() {
        delete(testStack);
    }

protected:
    virtual void SetUp() {
        testStack = new arrayStack();
    }
    arrayStack* testStack;
};

TEST_F(ArrayStackFixture, EmptyTest) {
    ASSERT_NO_FATAL_FAILURE(testStack->pop());
    ASSERT_EQ(testStack->pop(), NULL);
}

TEST_F(ArrayStackFixture, PushPopTest) {
    testStack->push(19);
    EXPECT_EQ(testStack->pop(), 19);
    testStack->push(1);
    testStack->push(2);
    EXPECT_EQ(testStack->pop(), 2);
    EXPECT_EQ(testStack->pop(), 1);

}
