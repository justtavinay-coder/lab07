cmake_minimum_required(VERSION 3.10)

include("cmake/HunterGate.cmake")
HunterGate(
  URL "https://github.com/justtavinay-coder/hunter/archive/refs/tags/lab07-v0.1.0.tar.gz"
  SHA1 "b872707578f873cbb0eb820e30db43bc14a16554"
  LOCAL
)

project(lab07 VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(BUILD_TESTS "Build tests" ON)

hunter_add_package(lab07_solver)
find_package(lab07_solver CONFIG REQUIRED)

add_executable(demo demo/main.cpp)
target_link_libraries(demo PRIVATE lab07_solver::lab07_solver)

if(BUILD_TESTS)
  enable_testing()

  hunter_add_package(GTest)
  find_package(GTest CONFIG REQUIRED)

  add_executable(check tests/solver_test.cpp)
  target_link_libraries(check PRIVATE lab07_solver::lab07_solver GTest::gtest_main)
  add_test(NAME check COMMAND check)
endif()
