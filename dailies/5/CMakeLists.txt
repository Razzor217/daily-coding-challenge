find_package(Boost REQUIRED)

add_library(metrics_hashing_uniformity INTERFACE)

target_include_directories(metrics_hashing_uniformity INTERFACE "${PROJECT_SOURCE_DIR}/5")
target_link_libraries(metrics_hashing_uniformity
    INTERFACE hashing_interface
    INTERFACE Boost::boost
)
