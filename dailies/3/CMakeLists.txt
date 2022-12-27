add_library(hashing_table_chaining INTERFACE)
target_include_directories(hashing_table_chaining INTERFACE "${PROJECT_SOURCE_DIR}/3")
target_link_libraries(hashing_table_chaining
    INTERFACE hashing_interface
    INTERFACE hashing_simple_functions
)
