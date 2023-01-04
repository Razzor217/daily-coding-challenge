/**
 * @file chi_squared.h
 * @author Max Beddies (max dot beddies at t dash online dot de)
 * @brief Implementation of the chi-squared test for hash functions
 * @version 0.1
 * @date 2023-01-02
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#ifndef METRICS_DETAIL_HASHING_CHI_SQUARED_HEADER
#define METRICS_DETAIL_HASHING_CHI_SQUARED_HEADER


#include <iostream>
#include <vector>

#include <hashing/function.h>


namespace metrics
{
    namespace detail
    {

        /**
         * @brief Compute the chi-squared statistic for a given type of hash functions
         * 
         * @tparam Hash Hash function to evaluate
         */
        template <typename Hash>
        class chi_squared
        {
        public:
            /// @brief Resulting type when performing the chi-squared test
            using result_type = double;

            /// @brief Hash function to evaluate
            using hash = Hash;

            using key_type = typename hash::key_type;
            using size_type = typename hash::size_type;


            /**
             * @brief Compute the chi-squared statistic of a given hash function
             * 
             * Performs Pearson's chi-squared test in order to evaluate the
             * uniformity of the given hash function.
             * 
             * @param h Hash function to evaluate
             * @param max_key Maximum value of keys to evaluate, i.e. \f$k\in[0,\ldots,\text{max_key}\f$
             * @param max_hash Maximum hash value, i.e. \f$h(k)\in[0,\ldots,\text{max_hash}]\f$
             * @return The statistic of the chi-squared distribution
             */
            result_type
            operator() (hash h, key_type const max_key, size_type const max_hash) const
            {
                std::uint64_t const n {static_cast<std::uint64_t>(max_key) + 1ULL};
                std::uint64_t const m {static_cast<std::uint64_t>(max_hash) + 1ULL};

                container c {populate_buckets(h, n, m)};

                result_type sum {};
                for (auto const& b : c)
                {
                    double const residual {b - n / static_cast<double>(m)};
                    sum += residual * residual;
                }

                return sum * m / n;
            }

        private:
            using container = std::vector<size_type>;

            container
            populate_buckets(hash h, std::uint64_t const n, std::uint64_t const m) const
            {
                container c(m);

                for (key_type k {}; k < n - 1; ++k)
                {
                    c[h(k)]++;
                }
                c[h(n - 1)]++;

                return c;
            }
        };

    } // !namespace detail
} // !namespace metrics


#endif // !METRICS_DETAIL_HASHING_CHI_SQUARED_HEADER
