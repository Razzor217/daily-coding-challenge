/**
 * @file merkle_damgard.h
 * @author Max Beddies (max dot beddies at t dash online dot de)
 * @brief Implementation of the Merkle-Damgard transformation
 * @version 0.1
 * @date 2022-12-28
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef HASHING_FUNCTION_MERKLE_DAMGARD_HEADER
#define HASHING_FUNCTION_MERKLE_DAMGARD_HEADER


#include <hashing/multiplication.h>
#include <hashing/traits.h>


namespace hashing
{

    template <
        typename Iterator,
        typename T = std::uint16_t,
        typename Key = std::uint32_t,
        typename Hash = multiplication_shift_xor<std::uint32_t, 16>,
        std::enable_if_t<std::conjunction<
            traits::is_iterator_to<Iterator, T>,
            traits::is_md_hasher<Hash, Key>>::value, bool> = true>
    class merkle_damgard
    {
    public:
        static_assert(sizeof(T) < sizeof(Key));
        static_assert(2U * sizeof(T) >= sizeof(Key));

        using iterator_type = Iterator;
        using value_type = T;
        using key_type = Key;
        using hash = Hash;

        key_type
        operator() (Iterator begin, Iterator end)
        {
            hash h {};
            key_type hash_value {seed};

            for (auto it = begin; it != end; ++it)
            {
                hash_value <<= 8U * sizeof(value_type);
                hash_value &= mask;
                hash_value = h(hash_value | *it);
            }

            return hash_value;
        }

        merkle_damgard() = default;
        explicit merkle_damgard(key_type const& seed) : seed {seed} {}

    private:
        static constexpr key_type const mask = ~0 << 8U * sizeof(value_type);
        key_type seed;
    };

} // !namespace hashing

#endif // !HASHING_FUNCTION_MERKLE_DAMGARD_HEADER
