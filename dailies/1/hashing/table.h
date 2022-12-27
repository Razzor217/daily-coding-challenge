/**
 * @file table.h
 * @author Max Beddies (max dot beddies at t dash online dot de)
 * @brief Interface of hash tables
 * @version 0.1
 * @date 2022-08-09
 *
 * @copyright Copyright (c) 2022
 *
 */


#ifndef HASHING_TABLE_INTERFACE_HEADER
#define HASHING_TABLE_INTERFACE_HEADER


#include <cstddef>
#include <optional>


namespace hashing
{

    /**
     * @brief Interface for hash tables
     *
     * @tparam key The hashed key type
     * @tparam T The mapped data type
     */
    template <typename Key, typename T>
    class table
    {
    public:
        /// @brief The hashed key type
        using key_type = Key;

        /// @brief The mapped data type
        using mapped_type = T;

        /// @brief Stored data type, i.e. pairs of `key_type` and `value_type`
        using value_type = std::pair<key_type, mapped_type>;

        /// @brief Reference to `value_type`
        using reference = value_type&;

        /// @brief Const reference to `value_type`
        using const_reference = value_type const&;


        /**
         * @brief Insert a new key-value pair into the hash table
         *
         * If the given key already exists, overwrite the corresponding value.
         *
         * @param value The key-value-pair to insert
         * @return true if the pair was inserted successfully
         * @return false otherwise
         */
        virtual
        bool
        insert(const_reference value) = 0;

        /**
         * @brief Find the mapped type to a given key, if the key exists
         *
         * @param key Key value of the element to search for
         * @return std::optional<mapped_type> The mapped element corresponding to `key`
         */
        virtual
        std::optional<mapped_type>
        find(key_type const& key) = 0;
    };


} // !namespace hashing


#endif // !HASHING_TABLE_INTERFACE_HEADER
