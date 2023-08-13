#include <filesystem>
#include <sstream>

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
using namespace testing;

#include "plotypus.h"

using namespace Plotypus;

TEST(TIP_PdfCairoSuite, NoEmptyFilename_Test)
{
    auto tip = TerminalInfo::PdfCairo();
    auto actual = tip.validate();

    ASSERT_FALSE(actual);
    ASSERT_TRUE(actual.getFirstResult());
    EXPECT_THROW(actual.trigger(), InvalidFilenameError);
}

TEST(TIP_PdfCairoSuite, WriteScript_Minimal)
{
    std::stringstream buffer;
    auto tip = TerminalInfo::PdfCairo();

    buffer.str("");
    tip.writeScript(buffer);
    EXPECT_THAT(buffer.str(), StartsWith("set term pdfcairo enhanced color font \"Sans,12\""));
}

TEST(TIP_PdfCairoSuite, WriteScript_WithFileName)
{
    std::stringstream buffer;
    auto tip = TerminalInfo::PdfCairo();
    tip.setPath("script.gnuplot");

    buffer.str("");
    tip.writeScript(buffer);
    EXPECT_THAT(buffer.str(), EndsWith("\nset output \"script.gnuplot\"\n\n"));
}

TEST(TIP_PdfCairoSuite, WriteScript_AllFragmentsAndReset)
{
    std::stringstream buffer;
    auto tip = TerminalInfo::PdfCairo();

    buffer.str("");
    tip.setBackground("#bada55");
    tip.setColor(false);
    tip.setEnhanced(false);
    tip.setFont("Times", 99);
    tip.setLineEnds(LineEnds::Butt);
    tip.setSize(1, 1);
    tip.setUserCode("foo bar");
    tip.writeScript(buffer);
    EXPECT_THAT(buffer.str(), StartsWith("set term pdfcairo noenhanced mono font \"Times,99\" butt background #bada55 size 1.000000,1.000000 foo bar"));

    buffer.str("");
    tip.reset();
    tip.writeScript(buffer);
    EXPECT_THAT(buffer.str(), StartsWith("set term pdfcairo enhanced color font \"Sans,12\""));
}

TEST(TIP_PdfCairoSuite, WriteScript_SizeWithUnits)
{
    std::stringstream buffer;
    auto tip = TerminalInfo::PdfCairo();

    buffer.str("");
    tip.setSize(1, 1);
    tip.writeScript(buffer);
    EXPECT_THAT(buffer.str(), StartsWith("set term pdfcairo enhanced color font \"Sans,12\" size 1.000000,1.000000"));

    buffer.str("");
    tip.setSizeUnit(LengthUnit::Centimeter);
    tip.writeScript(buffer);
    EXPECT_THAT(buffer.str(), StartsWith("set term pdfcairo enhanced color font \"Sans,12\" size 1.000000cm,1.000000cm"));

    ASSERT_THROW(tip.setSize(0, 0), InvalidArgumentError);
}
