add_executable(6 test.cpp)
target_link_libraries(6
    PRIVATE GTest::gtest_main
    PUBLIC graph_interface
)

include(GoogleTest)
gtest_discover_tests(6)
