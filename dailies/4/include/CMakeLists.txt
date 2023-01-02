add_library(hashing_function_merkle_damgard INTERFACE)
target_include_directories(hashing_function_merkle_damgard INTERFACE "${PROJECT_SOURCE_DIR}/4/include")
target_link_libraries(hashing_function_merkle_damgard
    INTERFACE hashing_interface
    INTERFACE hashing_simple_functions
)
