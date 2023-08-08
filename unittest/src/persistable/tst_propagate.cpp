#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "plotypus.h"

using namespace testing;
using namespace Plotypus;

class Propagate_Fixture : public ::testing::Test
{
    protected:
        std::shared_ptr<Persistable> root      = std::shared_ptr<Persistable>(new DefaultPropagatingPersistable);
        std::shared_ptr<Persistable> level_1_1 = std::shared_ptr<Persistable>(new DefaultPropagatingPersistable);
        std::shared_ptr<Persistable> level_1_2 = std::shared_ptr<Persistable>(new DefaultPersistable);
        std::shared_ptr<Persistable> level_1_3 = std::shared_ptr<Persistable>(new DefaultPersistable);
        std::shared_ptr<Persistable> level_2_1 = std::shared_ptr<Persistable>(new DefaultPropagatingPersistable);
        std::shared_ptr<Persistable> level_2_2 = std::shared_ptr<Persistable>(new DefaultPersistable);

        std::shared_ptr<DefaultPropagatingPersistable> getAsDPP(std::shared_ptr<Persistable>& ptr)
        {
            return std::dynamic_pointer_cast<DefaultPropagatingPersistable>(ptr);
        }

        std::shared_ptr<DefaultPersistable> getAsDP(std::shared_ptr<Persistable>& ptr)
        {
            return std::dynamic_pointer_cast<DefaultPersistable>(ptr);
        }

        void SetUp() override
        {
            getAsDPP(root)->reset();
            getAsDPP(level_1_1)->reset();
            getAsDP(level_1_2)->reset();
            getAsDP(level_1_3)->reset();
            getAsDPP(level_2_1)->reset();
            getAsDP(level_2_2)->reset();

            root->setPath("dir/root.dat");
            level_1_1->setPath("level_1_1");
            level_1_2->setPath("level_1_2");
            level_1_3->setPath("other");
            level_2_1->setPath("foo/level_2_1.ext");
            level_2_2->setPath("foo/level_2_2.ext");

            getAsDPP(root)->addSubscriber(level_1_1);
            getAsDPP(root)->addSubscriber(level_1_2);

            getAsDPP(level_1_1)->addSubscriber(level_2_1);
            getAsDPP(level_1_1)->addSubscriber(level_2_2);
        }
};

TEST_F(Propagate_Fixture, DefaultPropagatingPersistable_FullPropagation_Test)
{
    getAsDPP(root)->updateChildFileNames();

    EXPECT_EQ(root->getPath(), "dir/root.dat");

    EXPECT_EQ(level_1_1->getPath(), "dir/root_1");
    EXPECT_EQ(level_1_2->getPath(), "dir/root_2");
    EXPECT_EQ(level_1_3->getPath(), "other");
    EXPECT_EQ(level_2_1->getPath(), "dir/root_1_1.ext");
    EXPECT_EQ(level_2_2->getPath(), "dir/root_1_2.ext");
}

TEST_F(Propagate_Fixture, DefaultPropagatingPersistable_PartialPropagation_Test)
{
    getAsDPP(root)->setPropagateUpdateChildFileNames(false);
    getAsDPP(root)->updateChildFileNames();

    EXPECT_EQ(root->getPath(), "dir/root.dat");

    EXPECT_EQ(level_1_1->getPath(), "dir/root_1");
    EXPECT_EQ(level_1_2->getPath(), "dir/root_2");
    EXPECT_EQ(level_1_3->getPath(), "other");
    EXPECT_EQ(level_2_1->getPath(), "foo/level_2_1.ext");
    EXPECT_EQ(level_2_2->getPath(), "foo/level_2_2.ext");
}

TEST_F(Propagate_Fixture, DefaultPropagatingPersistable_ReplacementPropagation_Test)
{
    getAsDPP(root)->replaceSubscriber(level_1_1, level_1_3);
    getAsDPP(root)->updateChildFileNames();

    EXPECT_EQ(root->getPath(), "dir/root.dat");

    EXPECT_EQ(level_1_1->getPath(), "level_1_1");
    EXPECT_EQ(level_1_2->getPath(), "dir/root_2");
    EXPECT_EQ(level_1_3->getPath(), "dir/root_1");
    EXPECT_EQ(level_2_1->getPath(), "foo/level_2_1.ext");
    EXPECT_EQ(level_2_2->getPath(), "foo/level_2_2.ext");
}
