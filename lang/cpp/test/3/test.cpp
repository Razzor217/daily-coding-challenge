#include <gtest/gtest.h>

#include <string>

#include <hashing/chaining.h>


TEST(hashing_table_chaining_test, compile_test)
{
    hashing::chaining<std::size_t, std::string> t {};

    t.insert({0, "hallo"});
    t.find(0);

    EXPECT_TRUE(true);
}