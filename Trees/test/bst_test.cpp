#include "bst.hpp"

#include <gtest/gtest.h>

#include "mtest.hpp"

TEST(Init, InsertNoError) {
  MemoryLeakDetector leakD;
  BST b;
  ASSERT_NO_THROW(b.insert(1));
}
TEST(Init, Search) {
  MemoryLeakDetector leakD;
  BST b;
  ASSERT_NO_THROW(b.search(1));
  EXPECT_FALSE(b.search(1));
}
TEST(Init, Remove) {
  MemoryLeakDetector leakD;
  BST b;
  ASSERT_NO_THROW(b.remove(1));
}
TEST(Init, InOTraversal) {
  MemoryLeakDetector leakD;
  BST b;
  EXPECT_EQ(b.inorderTraversal().size(), 0);
}
TEST(Init, PreOTraversal) {
  MemoryLeakDetector leakD;
  BST b;
  EXPECT_EQ(b.preorderTraversal().size(), 0);
}
TEST(Init, PostOTraversal) {
  MemoryLeakDetector leakD;
  BST b;
  EXPECT_EQ(b.postorderTraversal().size(), 0);
}
TEST(Init, Min) {
  MemoryLeakDetector leakD;
  BST b;
  EXPECT_EQ(b.min(), INT_MIN);
}
TEST(Init, Max) {
  MemoryLeakDetector leakD;
  BST b;
  EXPECT_EQ(b.max(), INT_MAX);
}
TEST(Init, Successor) {
  MemoryLeakDetector leakD;
  BST b;
  EXPECT_EQ(b.successor(1), INT_MAX);
}
TEST(Init, Predecessor) {
  MemoryLeakDetector leakD;
  BST b;
  EXPECT_EQ(b.predecessor(1), INT_MIN);
}
