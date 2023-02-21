#include <gtest/gtest.h>

#include <graph/detail/edge_impl.h>
#include <graph/adjacency_list.h>

TEST(graph_adjacency_list_test, compile_test)
{
    EXPECT_TRUE(true);
}

TEST(graph_edge_impl_test, edge_constructor_test)
{
    graph::detail::edge_impl<int> e {1, 3};
}
