#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
using namespace testing;

#include "plotypus.h"

TEST(Validation_Suite, Validation_Test)
{
    using namespace Plotypus;

    ValidationResult v, s1, s2;
    EXPECT_TRUE(v);
    EXPECT_NO_THROW(v.trigger());
    EXPECT_EQ(v.getValidationReport(), "--- NO ERRORS ---\n");

    v.addError<InvalidArgumentError>("Invalid Argument", "x");
    EXPECT_FALSE(v);
    EXPECT_THROW(v.trigger(), InvalidArgumentError);
    std::string validationReport = v.getValidationReport();
    EXPECT_THAT(validationReport, StartsWith("InvalidArgumentError"));
    EXPECT_THAT(validationReport, HasSubstr("Invalid Argument"));
    EXPECT_THAT(validationReport, HasSubstr("from x"));

    v.addError<InvalidIndexError>("Invalid Index", "x");
    s1.addError<InvalidIndexError>("1", "y");
    s1.addError<InvalidIndexError>("2", "y");
    s1.addError<InvalidIndexError>("3", "y");

    s2.addError<InvalidIndexError>("1", "y");

    v.absorbValidationResult(s1, "x");
    v.absorbValidationResult(s2, "x");

    const std::vector stackTraceLengths {1, 1, 2, 2, 2, 2};
    const std::vector stackTraceHeads {"x", "x", "y", "y", "y", "y"};
    for (size_t i = 0; const auto& [errorPtr, stackTrace] : v.getResults())
    {
        EXPECT_EQ(stackTrace.size(), stackTraceLengths[i]);
        EXPECT_EQ(stackTrace.front(), "x");
        EXPECT_EQ(stackTrace.back(), stackTraceHeads[i]);
        ++i;
    }

    validationReport = v.getValidationReport();
    EXPECT_THAT(validationReport, HasSubstr(" from y\n"));
    EXPECT_THAT(validationReport, HasSubstr("  from x\n"));
}
