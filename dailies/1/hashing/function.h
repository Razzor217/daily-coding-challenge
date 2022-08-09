/**
 * @file function.h
 * @author Max Beddies (max dot beddies at t dash online dot de)
 * @brief Interface of hash functions
 * @version 0.1
 * @date 2022-08-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <cstddef>

namespace hashing
{

    template <class K, class V, std::size_t N> 
    class function
    {
    public:
        using key_type = K;
        using value_type = V;
        using size_type = std::size_t;

        using reference = value_type&;
        using const_reference = value_type const&;

        /**
         * @brief Compute the hash value of a given key
         * 
         * @param key Key to hash
         * 
         * @return value_type Resulting hash value
         */
        virtual
        value_type
        hash(key const&) const = 0;

    protected:
        constexpr size_type _size {N};
    };

} // !namespace hashing