/**
 * @file traits.h
 * @author Max Beddies (max dot beddies at t dash online dot de)
 * @brief Implementation details of type traits for hashing template definitions
 * @version 0.1
 * @date 2023-01-02
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef HASHING_FUNCTION_MD_TRAITS_DETAIL_HEADER
#define HASHING_FUNCTION_MD_TRAITS_DETAIL_HEADER


#include <iterator>
#include <type_traits>

#include <hashing/function.h>


namespace hashing
{
    namespace traits
    {
        namespace detail
        {

            /**
             * @brief Exposes the value type of a given iterator type
             *
             * @tparam Iterator The iterator type
             */
            template <typename Iterator>
            using iterator_value_type = std::decay_t<decltype(*std::declval<Iterator>())>;

            /**
             * @brief Determines whether a given hash function inherits from ::hashing::function<Key, Key>
             *
             * @tparam Hash The hash function
             * @tparam Key The hashed key type
             */
            template <typename Hash, typename Key>
            struct is_md_hasher_impl
            {
                /// @brief This member is only callable by hashers which inherit from ::hashing::function<Key, Key>
                static constexpr std::true_type
                is_callable_as_md_hasher(::hashing::function<Key, Key> const*);

                /// @brief This member is callablye by arbitrary hashers
                static constexpr std::false_type
                is_callable_as_md_hasher(...);

                /// @brief Exposes whether Hash inherits from ::hashing::function<Key, Key>
                using type = decltype(is_callable_as_md_hasher(std::declval<Hash*>()));
            };

        } // !namespace detail
    } // !namespace traits
} // !namespace hashing

#endif // !HASHING_FUNCTION_MD_TRAITS_DETAIL_HEADER

