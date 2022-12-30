enable_testing()

add_executable(
  linkedList_test
  linkedList_test.cpp
)
target_link_libraries(
  linkedList_test
  GTest::gtest_main
)
target_include_directories(
  linkedList_test PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/../src
)

include(GoogleTest)
gtest_discover_tests(linkedList_test)