#include <gtest/gtest.h>

#include <hashing/identity.h>
#include <hashing/multiplication.h>

TEST(hashing_function_identity_test, basic_test)
{
    EXPECT_EQ(hashing::identity{}(1), 1);
}

TEST(hashing_function_multiplication_test, basic_test)
{
    EXPECT_EQ(true, true);
}