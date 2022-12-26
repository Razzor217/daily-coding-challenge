/**
 * @file division.h
 * @author Max Beddies (max dot beddies at t dash online dot de)
 * @brief Implementation of division hashing
 * @version 0.1
 * @date 2022-12-26
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef HASHING_FUNCTION_DIVISION_HEADER
#define HASHING_FUNCTION_DIVISION_HEADER


#include <cmath>

#include <hashing/function.h>


namespace hashing
{

    /**
     * @brief Division hashing method
     *
     * Let \f$m>0\f$. Then \f$h(k)=k \mod m\f$.
     *
     * @tparam Key The hashed key type
     * @tparam M Upper bound for hash values
     */
    template <typename Key = std::uint32_t, std::uint32_t M = 1024>
    class division : public virtual function<Key, Key>
    {
    public:
        static_assert(M > 0);

        using key_type = typename function<Key, Key>::key_type;
        using size_type = typename function<Key, Key>::size_type;

        /// @see function::operator()()
        size_type
        operator() (key_type const& key) const override
        {
            return key % M;
        }
    };


} // !namespace hashing

#endif // !HASHING_FUNCTION_DIVISION_HEADER
