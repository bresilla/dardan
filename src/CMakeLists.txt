add_library(block STATIC inc/block.cpp)
add_executable(main main.cpp)

target_include_directories(main PRIVATE ${PROJECT_SOURCE_DIR}/src)
link_directories(/usr/lib)

target_link_libraries(main block)
