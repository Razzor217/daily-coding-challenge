#include <gtest/gtest.h>

#include <vector>

#include <hashing/merkle_damgard.h>

TEST(hashing_table_merkle_damgard_test, compile_test)
{
    hashing::merkle_damgard<std::vector<std::uint16_t>::iterator, std::uint16_t> md {};

    EXPECT_TRUE(true);
}
