add_subdirectory(minhook)

target_include_directories(Synthetic PRIVATE "${CMAKE_CURRENT_LIST_DIR}/minhook/include")