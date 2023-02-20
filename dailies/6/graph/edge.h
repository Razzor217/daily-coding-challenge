/**
 * @file edge.h
 * @author Max Beddies (max dot beddies at t dash online dot de)
 * @brief Interface definition for edge objects
 * @version 0.1
 * @date 2023-02-19
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef GRAPH_EDGE_INTERFACE_HEADER
#define GRAPH_EDGE_INTERFACE_HEADER


#include <graph/detail/traits.h>


namespace graph
{
    /**
     * @brief Interface for (hyper-) graph edges
     *
     * @tparam edge_implementation edge implementation
     */
    template <typename edge_implementation>
    class edge
    {
    public:
        /// edge implementation
        using edge_type = edge_implementation;
        /// const iterator for edge vertices
        using const_iterator = typename detail::edge_traits<edge_type>::const_iterator;

        /**
         * @brief Returns an iterator to the first edge vertex
         *
         * @return an iterator to the first vertex
         */
        const_iterator begin() const { return static_cast<edge_type const*>(this)->begin(); }

        /**
         * @brief Returns an iterator to the past-the-end edge vertex
         *
         * @return an iterator to the past-the-end vertex
         */
        const_iterator end() const { return static_cast<edge_type const*>(this)->end(); }
    };
} // namespace graph


#endif // !GRAPH_EDGE_INTERFACE_HEADER
