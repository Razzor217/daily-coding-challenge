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


#include <span>

#include <graph/edge.h>


namespace graph
{
    /**
     * @brief Interface for (hyper-) graphs
     *
     * @tparam graph_implementation graph implementation
     * @tparam edge_implementation edge implementation
     */
    template <typename graph_implementation, typename edge_implementation>
    class graph
    {
    public:
        /// graph implementation
        using graph_type = graph_implementation;
        /// edge implementation
        using edge_type = edge_implementation;
        /// const iterator for edges
        using const_edge_iterator = typename detail::edge_traits<edge_type>::const_iterator;
        /// size type
        using size_type = typename detail::edge_traits<edge_type>::size_type;

        /**
         * @brief Return the number of graph vertices
         *
         * @return the number of vertices
         */
        size_type vertices() const { return static_cast<graph_type const*>(this)->vertices(); }

        /**
         * @brief Return the number of graph edges
         *
         * @return the number of edges
         */
        size_type edges() const { return static_cast<graph_type const*>(this)->edges(); }

        /**
         * @brief Return an iterator to the first graph edge
         *
         * @return an iterator to the first edge
         */
        const_edge_iterator begin() const { return static_cast<graph_type const*>(this)->begin(); }

        /**
         * @brief Return an iterator to the past-the-end graph edge
         *
         * @return an iterator to the past-the-end edge
         */
        const_edge_iterator end() const { return static_cast<graph_type const*>(this)->end(); }
    };
} // namespace graph


#endif // !GRAPH_INTERFACE_HEADER

