#include <gtest/gtest.h>

#include <hashing/identity.h>
#include <hashing/division.h>
#include <hashing/multiplication.h>


// Identity

TEST(hashing_function_identity_test, basic_test)
{
    EXPECT_EQ(hashing::identity{}(1), 1);
}


// Division hashing

TEST(hashing_function_division_test, basic_test)
{
    EXPECT_EQ(hashing::division{}(0), 0);
}

TEST(hashing_function_division_test, lower_bound_test)
{
    EXPECT_GE(hashing::division{}(1), 0U);
    EXPECT_GE(hashing::division{}(0xFFFFFFFF), 0U);
}

TEST(hashing_function_division_test, upper_bound_test)
{
    EXPECT_LE(hashing::multiplication{}(1), 1024U);
    EXPECT_LE(hashing::multiplication{}(0xFFFFFFFF), 1024U);
}


// Multiplicative hashing method

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


// Multiplicative hashing using bit shifts

TEST(hashing_function_multiplication_shift_test, basic_test)
{
    EXPECT_EQ(hashing::multiplication_shift{}(0), 0);
}

TEST(hashing_function_multiplication_shift_test, inequality_test)
{
    EXPECT_NE(hashing::multiplication_shift{}(23), 23);
}

TEST(hashing_function_multiplication_shift_test, lower_bound_test)
{
    EXPECT_GE(hashing::multiplication_shift{}(1), 0U);
    EXPECT_GE(hashing::multiplication_shift{}(0xFFFFFFFF), 0U);
}

TEST(hashing_function_multiplication_shift_test, upper_bound_test)
{
    EXPECT_LE(hashing::multiplication_shift{}(1), 1024U);
    EXPECT_LE(hashing::multiplication_shift{}(0xFFFFFFFF), 1024U);
}


// Multiplicative hashing using bit shifts and XOR correction

TEST(hashing_function_multiplication_shift_xor_test, basic_test)
{
    EXPECT_EQ(hashing::multiplication_shift{}(0), 0);
}

TEST(hashing_function_multiplication_shift_xor_test, inequality_test)
{
    EXPECT_NE(hashing::multiplication_shift{}(23), 23);
}

TEST(hashing_function_multiplication_shift_xor_test, lower_bound_test)
{
    EXPECT_GE(hashing::multiplication_shift{}(1), 0U);
    EXPECT_GE(hashing::multiplication_shift{}(0xFFFFFFFF), 0U);
}

TEST(hashing_function_multiplication_shift_xor_test, upper_bound_test)
{
    EXPECT_LE(hashing::multiplication_shift{}(1), 1024U);
    EXPECT_LE(hashing::multiplication_shift{}(0xFFFFFFFF), 1024U);
}
