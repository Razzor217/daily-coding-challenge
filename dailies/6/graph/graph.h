/**
 * @file graph.h
 * @author Max Beddies (max dot beddies at t dash online dot de)
 * @brief Interface definition for graph objects
 * @version 0.1
 * @date 2023-02-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef GRAPH_INTERFACE_HEADER
#define GRAPH_INTERFACE_HEADER


#include <graph/edge.h>


namespace graph
{
    template <typename graph_implementation, typename edge_implementation>
    class graph
    {
    public:
        using graph_type = graph_implementation;
        using edge_type = edge_implementation;
        using const_edge_iterator = typename detail::edge_traits<edge_type>::const_iterator;
        using size_type = typename detail::edge_traits<edge_type>::size_type;

        size_type vertices() const { return static_cast<graph_type const*>(this)->vertices(); }
        size_type edges() const { return static_cast<graph_type const*>(this)->edges(); }

        const_edge_iterator begin() const { return static_cast<graph_type const*>(this)->begin(); }
        const_edge_iterator end() const { return static_cast<graph_type const*>(this)->end(); }
    };
} // namespace graph


#endif // !GRAPH_INTERFACE_HEADER

