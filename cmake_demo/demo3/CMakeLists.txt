cmake_minimum_required(VERSION 2.8)

project(demo3)

include_directories("${PROJECT_SOURCE_DIR}/include")
add_subdirectory(lib)
set(EXTRA_LIBS ${EXTRA_LIBS} wrap)

aux_source_directory(src DIR_SRCS)
add_executable(demo3 ${DIR_SRCS})
target_link_libraries(demo3 ${EXTRA_LIBS})
