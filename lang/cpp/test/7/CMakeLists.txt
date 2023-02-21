add_executable(7 test.cpp)
target_link_libraries(7
    PRIVATE GTest::gtest_main
    PUBLIC graph_adjacency_list
)

include(GoogleTest)
gtest_discover_tests(7)