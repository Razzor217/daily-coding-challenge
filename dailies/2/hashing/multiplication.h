/**
 * @file multiplication.h
 * @author Max Beddies (max dot beddies at t dash online dot de)
 * @brief Implementation of multiplicative hashing
 * @version 0.1
 * @date 2022-12-26
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef HASHING_FUNCTION_IDENTITY_HEADER
#define HASHING_FUNCTION_IDENTITY_HEADER


#include <hashing/function.h>


#define GOLDEN_RATIO_INVERSE  0.61803398874989484


namespace hashing
{

    // ..todo: default values

    template <
        typename Key = std::size_t,
        std::size_t M = 0,
        std::size_t W = 0,
        std::size_t a = 0>
    class multiplication : public virtual function<Key, Key>
    {
    public:
        static_assert(M > 0);
        static_assert(W > 0);
        static_assert(M != W);

        using key_type = typename function<Key, Key>::key_type;
        using size_type = typename function<Key, Key>::size_type;

        size_type
        operator() (key_type const& key) const override
        {
            return ((a * key) % W) / (W / M);
        }
    };


    template <
        typename Key = std::size_t,
        std::size_t m = 0,
        std::size_t a = 0>
    class shift : public virtual function<Key, Key>
    {
    public:
        static_assert(m > 0);
        static_assert(m != sizeof(int));

        using key_type = typename function<Key, Key>::key_type;
        using size_type = typename function<Key, Key>::size_type;

        size_type
        operator() (key_type const& key) const override
        {
            return (a * key) >> (w - m);
        }

    private:
        constexpr std::size_t const w {sizeof(int)};
    };

} // !namespace hashing

#endif // !HASHING_FUNCTION_IDENTITY_HEADER