add_executable(3 test.cpp)
target_link_libraries(3
    PRIVATE GTest::gtest_main
    PUBLIC hashing_table_chaining
)

include(GoogleTest)
gtest_discover_tests(3)
