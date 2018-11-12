cmake_minimum_required(VERSION 3.12)
project(kokkos_examples CXX)

list(APPEND CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -O3)
set(CMAKE_CXX_STANDARD 11)
set(KOKKOS_ENABLE_OPENMP ON)
#set(KOKKOS_ENABLE_PTHREAD ON)
set(CMAKE_CXX_EXTENSIONS OFF)
#set(KOKKOS_ENABLE_CUDA ON)
#set(KOKKOS_ARCH "HSW,Maxwell52")

add_subdirectory(kokkos ${PROJECT_BINARY_DIR}/kokkos)
include_directories(${Kokkos_INCLUDE_DIRS_RET})

add_executable(kokkos_examples main.cpp)
target_link_libraries(kokkos_examples kokkos)