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

            existingFile = existingSubdir / existingFileName;
            createFileOrStop(existingFile);

            nonExistingSubdir = root / nonExistingSubdirName;
            nonExistingFile   = existingSubdir / nonExistingFileName;
        }

        static void TearDownTestSuite()
        {
            std::filesystem::remove_all(root);
        }

        void SetUp() override
        {
            ASSERT_TRUE(ready);
        }

        void TearDown() override
        {}

};

std::filesystem::path TempDir_Fixture::root              = std::filesystem::path();
std::filesystem::path TempDir_Fixture::existingSubdir    = std::filesystem::path();
std::filesystem::path TempDir_Fixture::nonExistingSubdir = std::filesystem::path();
std::filesystem::path TempDir_Fixture::existingFile      = std::filesystem::path();
std::filesystem::path TempDir_Fixture::nonExistingFile   = std::filesystem::path();
bool TempDir_Fixture::ready = false;


TEST_F(TempDir_Fixture, DefaultPersistable_Default_Test)
{
    DefaultPersistable dpa;

    // test in implicit CWD
    std::filesystem::path filename = "report.pdf";
    dpa.setPath(filename);

    const ValidationResult expected = ValidationResult::SUCCESS;
    const ValidationResult actual = dpa.validate();
    EXPECT_EQ(actual, expected);
}

TEST_F(TempDir_Fixture, DefaultPersistable_NonExFileInExDir_Test)
{
    DefaultPersistable dpa;
    dpa.setPath(nonExistingFile);

    const ValidationResult expected = ValidationResult::SUCCESS;
    const ValidationResult actual = dpa.validate();
    EXPECT_EQ(actual, expected);
}

TEST_F(TempDir_Fixture, DefaultPersistable_ExFileInExDir_Test)
{
    DefaultPersistable dpa;
    dpa.setPath(existingFile);

    const ValidationResult actual = dpa.validate();
    ASSERT_FALSE(actual);
    ASSERT_TRUE(actual.getFirstResult());
    EXPECT_THROW(actual.trigger(), FileIOError);

    const std::list<std::string> messages = actual.getMessages();
    auto expectedValue = "already exists.";
    ASSERT_EQ(messages.size(), 1);
    EXPECT_THAT(messages.front(), EndsWith(expectedValue));
}

TEST_F(TempDir_Fixture, DefaultPersistable_ExFileOverwritable_Test)
{
    DefaultPersistable dpa;
    dpa.setPath(existingFile);
    dpa.setOverwrite(true);

    const ValidationResult expected = ValidationResult::SUCCESS;
    const ValidationResult actual = dpa.validate();
    EXPECT_EQ(actual, expected);
}

TEST_F(TempDir_Fixture, DefaultPersistable_NonExDir_Test)
{
    DefaultPersistable dpa;
    dpa.setPath(nonExistingSubdir / "foo");

    const ValidationResult expected = ValidationResult::SUCCESS;
    const ValidationResult actual = dpa.validate();
    ASSERT_EQ(actual, expected);
}

TEST_F(TempDir_Fixture, DefaultPersistable_NonExDirNoMakeDir_Test)
{
    DefaultPersistable dpa;
    dpa.setPath(nonExistingSubdir / "foo");
    dpa.setMakeDirectories(false);

    const ValidationResult actual = dpa.validate();
    ASSERT_FALSE(actual);
    EXPECT_THROW(actual.trigger(), FileIOError);

    const std::list<std::string> messages = actual.getMessages();
    const auto expectedValue = "does not exist.";
    ASSERT_EQ(messages.size(), 1);
    EXPECT_THAT(messages.front(), EndsWith(expectedValue));
}

TEST_F(TempDir_Fixture, DefaultPersistable_FileAsDir_Test)
{
    DefaultPersistable dpa;
    dpa.setPath(existingFile / "foo");
    dpa.setMakeDirectories(true);

    const ValidationResult actual = dpa.validate();
    ASSERT_FALSE(actual);
    EXPECT_THROW(actual.trigger(), FileIOError);

    const std::list<std::string> messages = actual.getMessages();
    const auto expectedValue = "is not a directory.";
    ASSERT_EQ(messages.size(), 1);
    EXPECT_THAT(messages.front(), EndsWith(expectedValue));
}
