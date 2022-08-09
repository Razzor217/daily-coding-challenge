/**
 * @file meta.h
 * @author Max Beddies (max dot beddies at t dash online dot de)
 * @brief Metaprogramming utilities
 * @version 0.1
 * @date 2022-08-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <type_traits>


namespace meta
{

    template <class... Ts>
    struct is_empty_pack : public std::bool_constant<sizeof...(Ts) == 0U> {};

    template <class...>
    struct is_empty_pack : public std::true_type {}; 

} // !namespace meta
