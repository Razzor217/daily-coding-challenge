#include <gtest/gtest.h>

#include <cstdint>

#include <hashing/identity.h>
#include <metrics/uniformity.h>


#include <limits>


#ifdef EVALUATE_FULL_32_BIT_KEY_RANGE
    #define KEY_RANGE 4294967296
#else
    #define KEY_RANGE 65536
#endif


TEST(metrics_hashing_chi_squared_test, statistic_identity_test)
{
    using hash = hashing::identity<std::uint32_t>;

    metrics::hashing::chi_squared<hash> m {};
    double const score = m(hash {}, KEY_RANGE, KEY_RANGE);

    EXPECT_FLOAT_EQ(score, 0.0);
}

TEST(metrics_hashing_chi_squared_test, p_value_identity_test)
{
    using hash = hashing::identity<std::uint32_t>;

    double const p_value = metrics::hashing::chi_squared_cdf<hash>(KEY_RANGE, KEY_RANGE);

    EXPECT_FLOAT_EQ(1.0 - p_value, 1.0);
}
