option(EVALUATE_FULL_KEY_RANGE "Evaluate hash functions using the full 32-bit key range" OFF)
if (EVALUATE_FULL_KEY_RANGE)
    target_compile_definitions(5 PRIVATE EVALUATE_FULL_32_BIT_KEY_RANGE)
endif()

add_executable(5 test.cpp)
target_link_libraries(5
    PRIVATE GTest::gtest_main
    PUBLIC metrics_hashing_uniformity
    PUBLIC hashing_simple_functions
    PUBLIC hashing_function_merkle_damgard
)

include(GoogleTest)
gtest_discover_tests(5)
