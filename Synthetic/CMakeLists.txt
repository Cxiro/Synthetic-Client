cmake_minimum_required(VERSION 3.20)
project(Synthetic VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)

add_library(Synthetic SHARED)

target_sources(Synthetic PRIVATE
    "Synthetic.cpp"
)

add_subdirectory(includes)

target_link_libraries(Synthetic PRIVATE minhook)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)