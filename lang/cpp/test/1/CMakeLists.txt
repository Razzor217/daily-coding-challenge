add_executable(1 test.cpp)
target_link_libraries(1
    PRIVATE GTest::gtest_main
    PUBLIC hashing_interface
)

include(GoogleTest)
gtest_discover_tests(1)