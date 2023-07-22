#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "plotypus.h"

using namespace testing;
using namespace Plotypus;

class TempDir_Fixture : public ::testing::Test
{
    protected:
        static std::filesystem::path root;
        static std::filesystem::path existingSubdir;
        static std::filesystem::path nonExistingSubdir;
        static std::filesystem::path existingFile;
        static std::filesystem::path nonExistingFile;
        static bool ready;

        static constexpr auto existingSubdirName = "existingSubDir";
        static constexpr auto nonExistingSubdirName = "nonExistingSubDir";
        static constexpr auto existingFileName = "existingFile";
        static constexpr auto nonExistingFileName = "nonExistingFile";

        static void createDirOrStop(const std::filesystem::path& path)
        {
            if (!ready)
            {
                return;
            }

            bool success = std::filesystem::create_directories(path);
            if (!success)
            {
                ready = false;
                FAIL() << "Could not create temp test dir: " << path.string();
            }
        }

        static void createFileOrStop(const std::filesystem::path& path)
        {
            if (!ready)
            {
                return;
            }

            std::string filename = path.string();
            std::ofstream hFile(filename, std::ios::binary);

            if (!hFile.is_open())
            {
                ready = false;
                FAIL() << "Could not create temp test dir: " << path.string();
            }
        }

        static void SetUpTestSuite()
        {
            ready = true;

            root = std::filesystem::temp_directory_path();
            root /= "PlotypusTest";
            createDirOrStop(root);

            existingSubdir = root / existingSubdirName;
            createDirOrStop(existingSubdir);

            nonExistingSubdir = root / nonExistingSubdirName;

            existingFile = existingSubdir / existingFileName;
            createFileOrStop(existingFile);

            nonExistingFile  = existingSubdir / nonExistingFileName;
        }

        static void TearDownTestSuite()
        {
            std::filesystem::remove_all(root);
        }

        void SetUp() override
        {
            ASSERT_TRUE(ready);
        }

        void TearDown () override
        {}

};

std::filesystem::path TempDir_Fixture::root              = std::filesystem::path();
std::filesystem::path TempDir_Fixture::existingSubdir    = std::filesystem::path();
std::filesystem::path TempDir_Fixture::nonExistingSubdir = std::filesystem::path();
std::filesystem::path TempDir_Fixture::existingFile      = std::filesystem::path();
std::filesystem::path TempDir_Fixture::nonExistingFile   = std::filesystem::path();
bool TempDir_Fixture::ready = false;


TEST_F(TempDir_Fixture, OutputPathProvider_Test)
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

TEST_F(TempDir_Fixture, PersistableImpl_Test)
{
    auto opp = OutputPathProvider();
    auto pis = PersistableImpl();

    // test in implicit CWD
    std::filesystem::path filename = opp.getOutputPath(OutputPathProvider::GeneratedFileType::Report);
    pis.setPath(filename);

    auto expected = ValidationResult::SUCCESS;
    auto actual = pis.validate();
    EXPECT_EQ(actual, expected);

    // test in explicit/absolute dir, nonexisting
    pis.setPath(nonExistingFile);

    expected = ValidationResult::SUCCESS;
    actual = pis.validate();
    EXPECT_EQ(actual, expected);

    // test in explicit/absolute dir, existing
    pis.setPath(existingFile);

    auto not_expected = ValidationResult::SUCCESS;
    actual = pis.validate();
    ASSERT_THAT(actual, Ne(not_expected));

    auto actualValue = actual.getError().what();
    auto expectedValue = "already exists.";
    EXPECT_THAT(actualValue, EndsWith(expectedValue));

    // allow overwriting
    pis.setOverwrite(true);
    expected = ValidationResult::SUCCESS;
    actual = pis.validate();
    EXPECT_EQ(actual, expected);

    // non-existing dir
    pis.setPath(nonExistingSubdir / "foo");
    actual = pis.validate();
    ASSERT_THAT(actual, Ne(not_expected));

    actualValue = actual.getError().what();
    expectedValue = "does not exist.";
    EXPECT_THAT(actualValue, EndsWith(expectedValue));

    // allow make dirs
    pis.setMakeDirectories(true);
    expected = ValidationResult::SUCCESS;
    actual = pis.validate();
    EXPECT_EQ(actual, expected);

    // parent "dir" is a file
    pis.setMakeDirectories(true);
    pis.setPath(existingFile / "foo");
    not_expected = ValidationResult::SUCCESS;
    actual = pis.validate();
    ASSERT_THAT(actual, Ne(not_expected));

    actualValue = actual.getError().what();
    expectedValue = "is not a directory.";
    EXPECT_THAT(actualValue, EndsWith(expectedValue));
}
