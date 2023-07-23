#include <iostream>
#include <sstream>

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
using namespace testing;

#include "plotypus.h"

class Collection_Fixture : public ::testing::Test
{
    protected:
        std::stringstream log;

        class Base
        {
            protected:
                int i;
                std::stringstream& log;

            public:
                Base(int i, std::stringstream& log) :
                    i(i),
                    log(log)
                {};

                virtual ~Base()
                {
                    log << "DTOR " << __PRETTY_FUNCTION__ << " @" << i << std::endl;
                }

                virtual void show()
                {
                    log << "BASE: i = " << i << std::endl;
                }
        };

        class Derived : public Base
        {
            public:
                Derived(int i, std::stringstream& log) : Base(i, log) {};
                virtual ~Derived()
                {
                    log << "DTOR " << __PRETTY_FUNCTION__ << " @" << i << std::endl;
                }

                virtual void show()
                {
                    log << "DERIVED: i = " << i << std::endl;
                }
        };
};

TEST_F(Collection_Fixture, Collection_Test)
{
    using namespace Plotypus;
    {
        DefaultCollection<Base> collection;
        ASSERT_THAT(collection.empty(), Eq(true));
        ASSERT_THAT(collection.size(), Eq(0));

        collection.add(new Base(1, log));
        collection.add(new Derived(2, log));
        collection.add(new Derived(3, log));
        collection.add(new Base(4, log));

        collection.forEach([](Base& x)
        {
            x.show();
        });
    }

    std::string expected =
        "BASE: i = 1\n"
        "DERIVED: i = 2\n"
        "DERIVED: i = 3\n"
        "BASE: i = 4\n"
        "DTOR virtual Collection_Fixture::Base::~Base() @1\n"
        "DTOR virtual Collection_Fixture::Derived::~Derived() @2\n"
        "DTOR virtual Collection_Fixture::Base::~Base() @2\n"
        "DTOR virtual Collection_Fixture::Derived::~Derived() @3\n"
        "DTOR virtual Collection_Fixture::Base::~Base() @3\n"
        "DTOR virtual Collection_Fixture::Base::~Base() @4\n";

    EXPECT_THAT(log.str(), Eq(expected));
}

