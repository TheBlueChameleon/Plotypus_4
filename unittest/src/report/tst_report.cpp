#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "plotypus.h"

using namespace testing;
using namespace Plotypus;

TEST(ReportSuite, DefaultStateTest)
{
    Report report;

    EXPECT_EQ(report.getPath().string(), "report.gnuplot");

    TerminalInfo::PdfCairo& tip = report.getTerminal<TerminalInfo::PdfCairo>();
    EXPECT_EQ(tip.getPath().string(), "report.pdf");


    EXPECT_EQ(report.getRunCommand(), "gnuplot $f");
    EXPECT_EQ(report.getParsedRunCommand(), "gnuplot \"report.gnuplot\"");
}
