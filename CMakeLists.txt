cmake_minimum_required(VERSION 3.26)
project(DSA)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()


# source files
file(GLOB SOURCE_FILES
        Search-algorithms/*.cpp
        Sorting-algorithms/*.cpp
)

# test files
file(GLOB TEST_FILES
        tests/*.cpp
)
add_executable(runTests
        ${SOURCE_FILES}
        ${TEST_FILES}
)

# where headers are located
target_include_directories(runTests PRIVATE
        ${CMAKE_SOURCE_DIR}/Search-algorithms
        ${CMAKE_SOURCE_DIR}/Sorting-algorithms
)

target_link_libraries(runTests gtest_main)

include(GoogleTest)
gtest_discover_tests(runTests)
