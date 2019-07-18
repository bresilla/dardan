add_executable(main main.cpp)

link_directories(/usr/lib)

add_library(snake block include/block.cpp)

target_link_libraries(main block)
