target_sources(Synthetic PRIVATE
    "Synthetic.cpp"
)

add_subdirectory(Hook)
add_subdirectory(Category)
add_subdirectory(Module)
add_subdirectory(Manager)
add_subdirectory(SDK)