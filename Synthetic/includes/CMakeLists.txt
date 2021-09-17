add_subdirectory(minhook)
add_subdirectory(gsl)

target_include_directories(Synthetic PRIVATE "${CMAKE_CURRENT_LIST_DIR}/minhook/include")
target_include_directories(Synthetic PRIVATE "${CMAKE_CURRENT_LIST_DIR}/gsl/include")