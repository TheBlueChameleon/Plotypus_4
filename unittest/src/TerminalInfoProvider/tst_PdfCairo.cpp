#include <filesystem>
#include <sstream>

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
using namespace testing;

#include "plotypus.h"

TEST(TIP_PdfCairoSuite, FileNameAsserts)
{
    using namespace Plotypus;

    auto tip = TerminalInfo::PdfCairo();

    auto actual = tip.validate();
    auto expected = ValidationResult::makeValidationResult<InvalidFilenameError>("Filename is empty.");
    ASSERT_EQ(bool(actual), false);
    EXPECT_EQ(actual, expected);
}

TEST(TIP_PdfCairoSuite, WriteScript)
{
    using namespace Plotypus;

    std::stringstream buffer;

    auto tip = TerminalInfo::PdfCairo();

    buffer.str("");
    tip.writeScript(buffer);
    EXPECT_THAT(buffer.str(), StartsWith("set term pdfcairo enhanced color font Sans,12 background"));

    buffer.str("");
    tip.setBackground("#bada55");
    tip.setColor(false);
    tip.setEnhanced(false);
    tip.setFont("Times", 99);
    tip.setLineEnds(LineEnds::Butt);
    tip.setUserCode("foo bar");
    tip.writeScript(buffer);
    EXPECT_THAT(buffer.str(), StartsWith("set term pdfcairo noenhanced mono font Times,99 butt background #bada55 foo bar"));

    buffer.str("");
    tip.reset();
    tip.writeScript(buffer);
    EXPECT_THAT(buffer.str(), StartsWith("set term pdfcairo enhanced color font Sans,12"));

    buffer.str("");
    tip.setSize(1, 1);
    tip.writeScript(buffer);
    EXPECT_THAT(buffer.str(), StartsWith("set term pdfcairo enhanced color font Sans,12 size 1.000000,1.000000"));

    buffer.str("");
    tip.setSizeUnit(LengthUnit::Centimeter);
    tip.writeScript(buffer);
    EXPECT_THAT(buffer.str(), StartsWith("set term pdfcairo enhanced color font Sans,12 size 1.000000cm,1.000000cm"));

    ASSERT_THROW(tip.setSize(0, 0), InvalidArgumentError);
}
