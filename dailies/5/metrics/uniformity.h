/**
 * @file hashing.h
 * @author Max Beddies (max dot beddies at t dash online dot de)
 * @brief Definition of useful metrics for the evaluation of hash functions
 * @version 0.1
 * @date 2023-01-02
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef METRICS_HASHING_UNIFORMITY_HEADER
#define METRICS_HASHING_UNIFORMITY_HEADER


#include <boost/math/distributions/chi_squared.hpp>

#include <metrics/detail/chi_squared.h>


namespace metrics
{
    namespace hashing
    {
        /**
         * @brief Perform Pearson's chi-squared test for uniformity of hash functions
         * 
         * @tparam hash Hash function to evaluate
         */
        template <typename hash>
        using chi_squared = ::metrics::detail::chi_squared<hash>;

        
        /**
         * @brief Perform Pearson's chi-squared test for uniformity of hash functions and compute the p-value
         * 
         * @tparam hash Hash function to evaluate
         * @param max_key Maximum value of keys to evaluate, i.e. \f$k\in[0,\ldots,\text{max_key}\f$
         * @param max_hash Maximum hash value, i.e. \f$h(k)\in[0,\ldots,\text{max_hash}\f$
         * @return p-value of the corresponding chi-squared distribution 
         */
        template <typename hash>
        typename chi_squared<hash>::result_type
        chi_squared_cdf(typename chi_squared<hash>::key_type const max_key, typename chi_squared<hash>::size_type const max_hash)
        {
            chi_squared<hash> m {};
            typename chi_squared<hash>::result_type stats = m(hash {}, max_key, max_hash);

            return boost::math::cdf(boost::math::chi_squared {static_cast<double>(max_hash)}, stats);
        }
    } // !namespace hashing
} // !namespace metrics


#endif // !METRICS_HASHING_UNIFORMITY_HEADER
