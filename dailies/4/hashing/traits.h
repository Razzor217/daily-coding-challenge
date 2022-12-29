/**
 * @file traits.h
 * @author Max Beddies (max dot beddies at t dash online dot de)
 * @brief Type trait definitions for hashing template definitions
 * @version 0.1
 * @date 2022-12-28
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef HASHING_FUNCTION_MD_TRAITS_HEADER
#define HASHING_FUNCTION_MD_TRAITS_HEADER


#include <iterator>
#include <type_traits>

#include <hashing/function.h>


namespace hashing
{
    namespace traits
    {
        template <typename Iterator>
        using iterator_value_type = std::decay_t<decltype(*std::declval<Iterator>())>;

        template <typename Iterator, typename T>
        using is_iterator_to = typename std::is_same<T, iterator_value_type<Iterator>>;

        namespace detail
        {
            template <typename Hash, typename Key>
            struct is_md_hasher_impl
            {
                static constexpr std::true_type
                is_callable_as_md_hasher(::hashing::function<Key, Key> const*);

                static constexpr std::false_type
                is_callable_as_md_hasher(...);

                using type = decltype(is_callable_as_md_hasher(std::declval<Hash*>()));
            };
        } // !namespace detail

        template <typename Hash, typename Key>
        using is_md_hasher = typename detail::is_md_hasher_impl<Hash, Key>::type;

    } // !namespace traits
} // !namespace hashing

#endif // !HASHING_FUNCTION_MD_TRAITS_HEADER
