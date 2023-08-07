#include <vector>

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
using namespace testing;

#include "plotypus.h"

TEST(StdRangeUtils_Suite, FindAndReplace_Direct_Test)
{
    std::vector<int> v = {1,2,3,4,5};

    Plotypus::findAndReplace(v, 3, -3);

    for (size_t idx = 0; int num :
         {
             1,2,-3,4,5
         })
    {
        EXPECT_EQ(v[idx], num);
        ++idx;
    }
}

TEST(StdRangeUtils_Suite, FindAndReplace_SharedPtr_Test)
{
    std::vector<std::shared_ptr<int>> v;
    for (int i = 1; i <= 5; ++i)
    {
        v.push_back(std::make_shared<int>(i));
    }

    const int offset = 2;
    const int val_pos = +3;
    const int val_neg = -3;

    std::shared_ptr<int> x = v[offset];
    std::shared_ptr<int> y = std::make_shared<int>(val_neg);
    Plotypus::findAndReplace(v, x, y);

    for (size_t idx = 0; int num :
         {
             1,2,-3,4,5
         })
    {
        EXPECT_EQ(*v[idx], num);
        ++idx;
    }

    // check that really the pointer in v has been replaced, rather than only overwriting the pointed-at address
    *y = val_pos;
    EXPECT_EQ(*v[offset], 3);

    *x = val_neg;
    EXPECT_EQ(*v[offset], 3);
}
