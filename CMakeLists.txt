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
        Sorting-algorithms/Tests/test_sort.cpp
        Sorting-algorithms/Tests/test.cpp
        Linked-list/linked_list_basic.cpp
        "Placement Training/fibonacci_series_iterative_way.cpp"
        "Placement Training/fibonacci_series.cpp"
        "Placement Training/sum_elements_into_array.cpp"
        "Placement Training/print_even_no_list.cpp"
        "Placement Training/sum_elements_where_end_2and4.cpp"
        "Placement Training/find_max_and_min.cpp"
        Sorting-algorithms/Tests/test-input.cpp
        Sorting-algorithms/Tests/test_sorting_next.cpp
        "Sorting-algorithms/SRM PLACEMENT TRAINING/sort-algorithms.cpp"
        Advanced-DSA-Training/Day-1/level-1.cpp
        Advanced-DSA-Training/Day-1/level-2.cpp
        Advanced-DSA-Training/Day-1/level-3.cpp
        Advanced-DSA-Training/Day-1/level-3.cpp
        Advanced-DSA-Training/Day-1/level-4.cpp
        Advanced-DSA-Training/Day-2/isprime.cpp
        Advanced-DSA-Training/Day-2/lab1.cpp
        Advanced-DSA-Training/Day-2/lab.cpp
        Advanced-DSA-Training/Day-2/lab.cpp
        Advanced-DSA-Training/Day-1/level-3-part.cpp
        Advanced-DSA-Training/Day-1/level-5.cpp
        Advanced-DSA-Training/Day-1/level-5.cpp
        Advanced-DSA-Training/Day-1/level-part-2.cpp
        Advanced-DSA-Training/Day-3/string_problem2.cpp
        "Advanced-DSA-Training/Day-3/Kadane's Algorithm.cpp"
        Advanced-DSA-Training/Day-3/subarray_sum_equals_k.cpp
        Advanced-DSA-Training/Day-3/linked_list.cpp
        Advanced-DSA-Training/Day-4/stack-array.cpp
        Advanced-DSA-Training/Day-4/circular_queue_array.cpp
)

# where headers are located
target_include_directories(runTests PRIVATE
        ${CMAKE_SOURCE_DIR}/Search-algorithms
        ${CMAKE_SOURCE_DIR}/Sorting-algorithms
)

target_link_libraries(runTests gtest_main)

include(GoogleTest)
gtest_discover_tests(runTests)