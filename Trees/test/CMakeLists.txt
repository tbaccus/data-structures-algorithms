enable_testing()

add_executable(
  folder_test
  folder_test.cpp
)
target_link_libraries(
  folder_test
  folder
  GTest::gtest_main
)
target_include_directories(
  folder_test PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/../src
)

add_executable(
  bst_test
  bst_test.cpp
)
target_link_libraries(
  bst_test
  bst
  GTest::gtest_main
)
target_include_directories(
  bst_test PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/../src
)

include(GoogleTest)
gtest_discover_tests(folder_test)
gtest_discover_tests(bst_test)