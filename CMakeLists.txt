cmake_minimum_required(VERSION 2.8)

project(linux_program)

set(CMAKE_C_FLAGS "-g")

include_directories("${PROJECT_SOURCE_DIR}/include")

#add_subdirectory(lib)
add_subdirectory(tests)
add_subdirectory(src)

#aux_source_directory(src DIR_SRCS)
#add_executable(demo3 ${DIR_SRCS})
#target_link_libraries(demo3 ${EXTRA_LIBS})
