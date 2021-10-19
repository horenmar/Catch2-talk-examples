cmake_minimum_required(VERSION 3.15)
project(Catch2-examples LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(Catch2)

add_executable(generic-matchers generic-matchers.cpp)
target_link_libraries(generic-matchers PRIVATE Catch2::Catch2WithMain)

add_executable(generators generators.cpp)
target_link_libraries(generators PRIVATE Catch2::Catch2WithMain)

add_executable(templated-test-cases templated-test-cases.cpp)
target_link_libraries(templated-test-cases PRIVATE Catch2::Catch2WithMain)

add_executable(listeners listeners.cpp)
target_link_libraries(listeners PRIVATE Catch2::Catch2WithMain)

add_executable(benchmarks benchmarks.cpp)
target_link_libraries(benchmarks PRIVATE Catch2::Catch2WithMain)

add_executable(simple-usage simple-usage.cpp)
target_link_libraries(simple-usage PRIVATE Catch2::Catch2WithMain)
