/**
 * @file chaining.h
 * @author Max Beddies (max dot beddies at t dash online dot de)
 * @brief Implementation of a hash table using chaining
 * @version 0.1
 * @date 2022-12-27
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef HASHING_TABLE_CHAINING_HEADER
#define HASHING_TABLE_CHAINING_HEADER


#include <list>
#include <vector>

#include <hashing/table.h>
#include <hashing/multiplication.h>

namespace hashing
{

    template <
        typename Key,
        typename T,
        std::size_t LogTableSize = 10,
        typename Hash = multiplication_shift_xor<Key, LogTableSize>>
    class chaining : public virtual table<Key, T>
    {
    public:
        using key_type = typename table<Key, T>::key_type;
        using mapped_type = typename table<Key, T>::mapped_type;
        using value_type = typename table<Key, T>::value_type;
        using reference = typename table<Key, T>::reference;
        using const_reference = typename table<Key, T>::const_reference;

        /// @brief Hash function
        using hash = Hash;

        /// @see table::insert()
        bool
        insert(const_reference value) override
        {
            c[h(value.first)].push_back(value);
            return true;
        }

        /// @see table::find()
        std::optional<mapped_type>
        find(key_type const& key) override
        {
            auto it = std::find_if
            (
                c[h(key)].begin(),
                c[h(key)].end(),
                [key] (const_reference value) { return value.first == key; }
            );

            if (it != c[h(key)].end())
            {
                return it->second;
            }

            return std::nullopt;
        }

    private:
        using container = std::vector<std::list<value_type>>;

        container c {1U << LogTableSize};
        hash h {};

    };




} // !namespace hashing


#endif // !HASHING_TABLE_CHAINING_HEADER
