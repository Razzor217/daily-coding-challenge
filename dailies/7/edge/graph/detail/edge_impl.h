/**
 * @file edge_impl.h
 * @author Max Beddies (max dot beddies at t dash online dot de)
 * @brief Implementation of graph edges
 * @version 0.1
 * @date 2023-02-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef GRAPH_EDGE_IMPL_HEADER
#define GRAPH_EDGE_IMPL_HEADER


#include <vector>

#include <graph/detail/traits_impl.h>
#include <graph/edge.h>

namespace graph
{
    namespace detail
    {
        template <typename Size>
        class edge_impl : public ::graph::edge<edge_impl<Size>>
        {
        public:
            using const_iterator = typename edge_traits<edge_impl>::const_iterator;
            using size_type = typename edge_traits<edge_impl>::size_type;

            const_iterator begin() const { return m_vertices.cbegin(); }
            const_iterator end() const { return m_vertices.cend(); }

            edge_impl(std::initializer_list<size_type> const& init)
                : m_vertices {init}
            {
            }

        private:
            std::vector<size_type> m_vertices;
        };
    }

} // namespace graph


#endif // !GRAPH_EDGE_IMPL_HEADER
