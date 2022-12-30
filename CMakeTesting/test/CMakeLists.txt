enable_testing()

add_executable(
  hellotest
  hellotest.cpp
)
target_link_libraries(
  hellotest LINK_PUBLIC main
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(hellotest)