add_library(graph_edge INTERFACE)
target_include_directories(graph_edge INTERFACE "${PROJECT_SOURCE_DIR}/7/edge")
target_link_libraries(graph_edge
    INTERFACE graph_interface
)

add_library(graph_adjacency_list INTERFACE)
target_include_directories(graph_adjacency_list INTERFACE "${PROJECT_SOURCE_DIR}/7/adjacency_list")
target_link_libraries(graph_adjacency_list
    INTERFACE graph_interface
    INTERFACE graph_edge
)
