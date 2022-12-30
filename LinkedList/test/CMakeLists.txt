enable_testing()

add_executable(
  singlyLinkedList_test
  singlyLinkedList_test.cpp
)
target_link_libraries(
  singlyLinkedList_test
  GTest::gtest_main
)
target_include_directories(
  singlyLinkedList_test PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/../src
)

add_executable(
  circularLinkedList_test
  circularLinkedList_test.cpp
)
target_link_libraries(
  circularLinkedList_test
  GTest::gtest_main
)
target_include_directories(
  circularLinkedList_test PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/../src
)

include(GoogleTest)
gtest_discover_tests(singlyLinkedList_test)
gtest_discover_tests(circularLinkedList_test)