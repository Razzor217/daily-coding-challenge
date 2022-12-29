add_executable(4 test.cpp)
target_link_libraries(4
    PRIVATE GTest::gtest_main
    PUBLIC hashing_function_merkle_damgard
)

include(GoogleTest)
gtest_discover_tests(4)
