cmake_minimum_required(VERSION 3.14)
project(perception_project)

set(CMAKE_CXX_STANDARD 17)

# -------------------------------
# Main Perception Binary
# -------------------------------
# Source files
set(SRC_FILES
    src/perception.cpp
    src/main.cpp
)

include_directories(
    include
    /usr/include/dlt
)

link_directories(/usr/lib)

add_executable(perception_main ${SRC_FILES})
target_link_libraries(perception_main dlt)

# -------------------------------
# GoogleTest Setup (FetchContent)
# -------------------------------
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# -------------------------------
# Unit Test Target
# -------------------------------
set(TEST_FILES
    tests/test_perception.cpp
    src/perception.cpp
)

add_executable(test_perception ${TEST_FILES})
target_include_directories(test_perception PRIVATE include)
target_link_libraries(test_perception gtest gtest_main pthread)

add_test(NAME PerceptionUnitTests COMMAND test_perception)

