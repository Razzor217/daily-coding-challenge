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


#include "meta.h"

#include <cstddef>


namespace hashing
{

    template <class hash, class... functions>
    using is_same = std::disjunction<std::conjunction<std::is_same<hash, functions>...>, meta::is_empty_pack<functions...>>;


    template <class K, class V, std::size_t N, class hash, class... functions, class = std::enable_if_t<is_same<hash, functions...>::value, void>>
    class table
    {
    public:
        using key_type = K;
        using value_type = V;
        using size_type = std::size_t;
        using hash_function = hash;

        using reference = value_type&;
        using const_reference = value_type const&;


        virtual
        void
        insert(const_reference) = 0;


        virtual
        value_type
        find(key_type const&) const = 0;

    protected:
        constexpr size_type _size {N};
    };


} // !namespace hashing


#endif // !HASHING_TABLE_INTERFACE_HEADER
