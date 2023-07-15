#include <iostream>

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace testing;

TEST(Foo_Suite, First_Test)
{
    EXPECT_EQ(1, 1);
    ASSERT_THAT(0, Eq(0));
}


TEST(Foo_Suite, Second_Test)
{
    EXPECT_EQ(1, 1);
    ASSERT_THAT(0, Eq(0));
}
