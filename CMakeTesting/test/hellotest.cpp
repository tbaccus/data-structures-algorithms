#include <gtest/gtest.h>
#include "main.h"

TEST(HelloTest, BasicAssertions) {
  EXPECT_STREQ(testf(3).c_str(), "lll");
  EXPECT_STREQ(testf(0).c_str(), "");
  EXPECT_STREQ(testf(-1).c_str(), "");
  EXPECT_STREQ(testf(5).c_str(), "lllll");
}