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


#include <hashing/detail/traits.h>


namespace hashing
{
    namespace traits
    {

        /**
         * @brief Determines whether an iterator points to data of a given type
         *
         * @tparam Iterator The iterator type to check
         * @tparam T The desired value type
         */
        template <typename Iterator, typename T>
        using is_iterator_to = typename std::is_same<T, detail::iterator_value_type<Iterator>>;

        /**
         * @brief Determines whether Hash inherits from ::hashing::function<Key, Key>
         *
         * @tparam Hash The hash function
         * @tparam Key The hashed key type
         */
        template <typename Hash, typename Key>
        using is_md_hasher = typename detail::is_md_hasher_impl<Hash, Key>::type;

    } // !namespace traits
} // !namespace hashing

#endif // !HASHING_FUNCTION_MD_TRAITS_HEADER
