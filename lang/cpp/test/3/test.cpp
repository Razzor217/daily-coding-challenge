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

TEST(hashing_table_chaining_test, insertion_batch_test)
{
    hashing::chaining<std::size_t, std::size_t> t {};

    for (std::size_t i {}; i < 2048U; ++i)
    {
        EXPECT_TRUE(t.insert({i, i}));
    }
}

TEST(hashing_table_chaining_test, find_basic_test)
{
    hashing::chaining<std::size_t, std::string> t {};

    t.insert({0, "hallo"});

    auto const result = t.find(0);
    EXPECT_TRUE(result.has_value());
    EXPECT_EQ(result.value(), "hallo");
}

TEST(hashing_table_chaining_test, find_collision_test)
{
    hashing::chaining<std::size_t, std::size_t> t {};

    for (std::size_t i {}; i < 2048U; ++i)
    {
        t.insert({i, i});
    }

    for (std::size_t i {}; i < 2048U; ++i)
    {
        auto const result = t.find(i);
        EXPECT_TRUE(result.has_value());
        EXPECT_EQ(result.value(), i);
    }
}

TEST(hashing_table_chaining_test, find_optional_test)
{
    hashing::chaining<std::size_t, std::string> t {};

    t.insert({0, "hallo"});

    auto const result = t.find(1);
    EXPECT_FALSE(result.has_value());
}
