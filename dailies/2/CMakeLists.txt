add_library(hashing_simple_functions INTERFACE)
target_include_directories(hashing_simple_functions INTERFACE "${PROJECT_SOURCE_DIR}/2")
target_link_libraries(hashing_simple_functions
    INTERFACE hashing_interface
)
