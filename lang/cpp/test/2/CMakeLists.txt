add_executable(2 test.cpp)
target_link_libraries(2
    PRIVATE GTest::gtest_main
    PUBLIC hashing_simple_functions
)

include(GoogleTest)
gtest_discover_tests(2)