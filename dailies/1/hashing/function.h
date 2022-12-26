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

#ifndef HASHING_FUNCTION_INTERFACE_HEADER
#define HASHING_FUNCTION_INTERFACE_HEADER


#include <cstddef>


namespace hashing
{

    /**
     * @brief Interface for hash functors.
     *
     * @tparam key The hashed key type
     * @tparam size The hash value for keys of type `key`
     */
    template <typename Key = std::size_t, typename Size = std::size_t>
    class function
    {
    public:
        /// @brief The hashed key type
        using key_type = Key;

        /// @brief The hash value for keys of type `key_type`
        using size_type = Size;

        /**
         * @brief Computes the hash value for a given key
         *
         * @param key The key to hash
         *
         * @return size_type The resulting hash
         */
        virtual
        size_type
        operator()(key_type const& key) const = 0;
    };

} // !namespace hashing


#endif // !HASHING_FUNCTION_INTERFACE_HEADER
