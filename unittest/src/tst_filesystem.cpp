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

            existingSubdir = root / "existingSubDir";
            createDirOrStop(existingSubdir);

            nonExistingSubdir = root / "existingSubDir";

            existingFile = existingSubdir / "file";
            createFileOrStop(existingFile);

            nonExistingFile  = existingSubdir / "nonExistingFile";
        }

        static void TearDownTestSuite()
        {
            std::filesystem::remove_all(root);
        }

        void SetUp()
        {
            ASSERT_TRUE(ready);
        }

        void TearDown()
        {
            std::cout << "TearDown T#" << std::endl;
        }

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

    opp.setBaseDirectory("<invalid>");
}


TEST_F(TempDir_Fixture, Second_Test)
{
    EXPECT_EQ(1, 1);
    ASSERT_THAT(0, Eq(0));

    std::cout << "running T2" << std::endl;
}
