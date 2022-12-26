#include <gtest/gtest.h>

#include <hashing/identity.h>
#include <hashing/multiplication.h>

TEST(hashing_function_identity_test, basic_test)
{
    EXPECT_EQ(hashing::identity{}(1), 1);
}

TEST(hashing_function_multiplication_test, basic_test)
{
    EXPECT_EQ(hashing::multiplication{}(0), 0);
}

TEST(hashing_function_multiplication_test, inequality_test)
{
    EXPECT_NE(hashing::multiplication{}(23), 23);
}

TEST(hashing_function_multiplication_test, lower_bound_test)
{
    EXPECT_GE(hashing::multiplication{}(1), 0U);
    EXPECT_GE(hashing::multiplication{}(0xFFFFFFFF), 0U);
}

TEST(hashing_function_multiplication_test, upper_bound_test)
{
    EXPECT_LE(hashing::multiplication{}(1), 1024U);
    EXPECT_LE(hashing::multiplication{}(0xFFFFFFFF), 1024U);
}
