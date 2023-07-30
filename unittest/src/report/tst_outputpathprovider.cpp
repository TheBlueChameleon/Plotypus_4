#include <string>

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "plotypus.h"

using namespace testing;
using namespace Plotypus;

TEST(OutputPathProvider_Suite, OutputPathProvider_Test)
{
    auto opp = OutputPathProvider();

    std::string expected = "report.pdf";
    std::string actual = opp.getOutputPathString(OutputPathProvider::GeneratedFileType::Report);
    EXPECT_EQ(actual, expected);

    expected = "report_foo.pdf";
    actual = opp.getOutputPathString(OutputPathProvider::GeneratedFileType::Report, "foo");
    EXPECT_EQ(actual, expected);

    expected = "report_99.pdf";
    actual = opp.getOutputPathString(OutputPathProvider::GeneratedFileType::Report, 99);
    EXPECT_EQ(actual, expected);

    expected = "report_99_1.pdf";
    actual = opp.getOutputPathString(OutputPathProvider::GeneratedFileType::Report, 99, 1);
    EXPECT_EQ(actual, expected);

    // actually no checks for invalid characters in filenames
    opp.setBaseDirectory("<invalid>");
    opp.setBaseFilename("<invalid>");
    opp.setExtension(OutputPathProvider::GeneratedFileType::Report, "<invalid>");
    expected = "<invalid>/<invalid>.<invalid>";
    actual = opp.getOutputPathString(OutputPathProvider::GeneratedFileType::Report);
    EXPECT_EQ(actual, expected);
}
