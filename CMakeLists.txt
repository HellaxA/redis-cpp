cmake_minimum_required(VERSION 3.13)

project(redis-starter-cpp)

set(CMAKE_CXX_STANDARD 23) # Enable the C++23 standard
set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(Threads REQUIRED)
find_package(asio CONFIG REQUIRED)
find_package(GTest CONFIG REQUIRED)

file(GLOB_RECURSE SOURCE_FILES src/*.cpp)
list(REMOVE_ITEM SOURCE_FILES ${CMAKE_SOURCE_DIR}/src/main.cpp)

add_executable(redis src/main.cpp ${SOURCE_FILES})

target_link_libraries(redis PRIVATE asio asio::asio)
target_link_libraries(redis PRIVATE Threads::Threads)

# Test executable (excludes main.cpp, links gtest's own main)
file(GLOB_RECURSE TEST_FILES tests/*.cpp)
add_executable(unit_tests ${SOURCE_FILES} ${TEST_FILES})
target_include_directories(unit_tests PRIVATE src)
target_link_libraries(unit_tests PRIVATE
  asio asio::asio
  Threads::Threads
  GTest::gtest
  GTest::gtest_main
)

enable_testing()
include(GoogleTest)
gtest_discover_tests(unit_tests)
