/**
 * @file traits_impl.h
 * @author Max Beddies (max dot beddies at t dash online dot de)
 * @brief Implementation of graph edge traits
 * @version 0.1
 * @date 2023-02-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef GRAPH_DETAIL_EDGE_TRAITS_IMPL_HEADER
#define GRAPH_DETAIL_EDGE_TRAITS_IMPL_HEADER


#include <vector>

#include <graph/detail/traits.h>


namespace graph
{
    namespace detail
    {
        // forward declaration
        template <typename Size>
        class edge_impl;

        template <typename Size>
        class edge_traits<edge_impl<Size>>
        {
        public:
            using size_type = Size;
            /// TODO: check against __gcc_lib::__normal_iterator
            using const_iterator = std::vector<size_type>::const_iterator;
        };

    } // namespace detail
} // namespace graph


#endif // !GRAPH_DETAIL_EDGE_TRAITS_IMPL_HEADER
