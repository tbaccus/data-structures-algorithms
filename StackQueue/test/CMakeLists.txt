enable_testing()

add_executable(
  stack_test
  stack_test.cpp
)
target_link_libraries(
  stack_test
  GTest::gtest_main
)
target_include_directories(
  stack_test PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/../src
)

add_executable(
  queue_test
  queue_test.cpp
)
target_link_libraries(
  queue_test
  GTest::gtest_main
)
target_include_directories(
  queue_test PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/../src
)

include(GoogleTest)
gtest_discover_tests(stack_test)
gtest_discover_tests(queue_test)