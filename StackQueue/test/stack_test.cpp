#include "stack.hpp"

#include <gtest/gtest.h>

#include "mtest.hpp"

TEST(Push, IntSingle) {
  MemoryLeakDetector leakD;
  LStack<int> s;
  s.push(-1);
  EXPECT_EQ(s.peek(), -1);
}
TEST(Push, IntLarge) {
  MemoryLeakDetector leakD;
  LStack<int> s;
  for (int i = -1'000'000; i < 1'000'000; i++) {
    s.push(i);
    EXPECT_EQ(s.peek(), i);
  }
}
TEST(Push, DoubleSingle) {
  MemoryLeakDetector leakD;
  LStack<double> s;
  s.push(-1.1);
  EXPECT_EQ(s.peek(), -1.1);
}
TEST(Push, DoubleLarge) {
  MemoryLeakDetector leakD;
  LStack<double> s;
  for (int i = -1'000'000; i < 1'000'000; i++) {
    s.push(i / 100.0);
    EXPECT_EQ(s.peek(), i / 100.0);
  }
}
TEST(Push, VectorSingle) {
  MemoryLeakDetector leakD;
  LStack<std::vector<int>> s;
  std::vector<int> n(10, 0);
  s.push(n);
  EXPECT_EQ(s.peek(), n);
}
TEST(Push, VectorLarge) {
  MemoryLeakDetector leakD;
  LStack<std::vector<int>> s;
  for (int i = -5'000; i < 5'000; i++) {
    std::vector<int> n(50, i);
    s.push(n);
    EXPECT_EQ(s.peek(), n);
  }
}

TEST(Pop, OOB) {
  MemoryLeakDetector leakD;
  LStack<int> s;
  EXPECT_THROW(s.pop(), std::out_of_range);
}
TEST(Pop, Single) {
  MemoryLeakDetector leakD;
  LStack<int> s;
  s.push(1);
  EXPECT_EQ(s.pop(), 1);
  EXPECT_THROW(s.pop(), std::out_of_range);
}
TEST(Pop, Multiple) {
  MemoryLeakDetector leakD;
  LStack<int> s;
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);
  EXPECT_EQ(s.pop(), 4);
  EXPECT_EQ(s.pop(), 3);
  EXPECT_EQ(s.pop(), 2);
  EXPECT_EQ(s.pop(), 1);
  EXPECT_THROW(s.pop(), std::out_of_range);
}
TEST(Pop, Empty) {
  MemoryLeakDetector leakD;
  LStack<int> s;
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);
  EXPECT_EQ(s.pop(), 4);
  EXPECT_EQ(s.pop(), 3);
  EXPECT_EQ(s.pop(), 2);
  EXPECT_EQ(s.pop(), 1);
  s.push(4);
  EXPECT_EQ(s.pop(), 4);
  EXPECT_THROW(s.pop(), std::out_of_range);
}

TEST(Peek, OOB) {
  MemoryLeakDetector leakD;
  LStack<int> s;
  EXPECT_THROW(s.peek(), std::out_of_range);
}
TEST(Peek, Single) {
  MemoryLeakDetector leakD;
  LStack<int> s;
  s.push(1);
  EXPECT_EQ(s.peek(), 1);
}
TEST(Peek, Multiple) {
  MemoryLeakDetector leakD;
  LStack<int> s;
  s.push(1);
  EXPECT_EQ(s.peek(), 1);
  s.push(2);
  EXPECT_EQ(s.peek(), 2);
  s.push(3);
  s.push(4);
  EXPECT_EQ(s.peek(), 4);
  EXPECT_EQ(s.peek(), 4);
  s.pop();
  EXPECT_EQ(s.peek(), 3);
  EXPECT_EQ(s.peek(), 3);
}

TEST(Empty, Empty) {
  MemoryLeakDetector leakD;
  LStack<int> s;
  EXPECT_TRUE(s.empty());
}
TEST(Empty, NotEmpty) {
  MemoryLeakDetector leakD;
  LStack<int> s;
  s.push(1);
  EXPECT_FALSE(s.empty());
}
TEST(Empty, Changed) {
  MemoryLeakDetector leakD;
  LStack<int> s;
  s.push(1);
  ASSERT_FALSE(s.empty());
  s.pop();
  EXPECT_TRUE(s.empty());
  s.push(2);
  EXPECT_FALSE(s.empty());
}

TEST(Size, Zero) {
  MemoryLeakDetector leakD;
  LStack<int> s;
  EXPECT_EQ(s.size(), 0);
}
TEST(Size, Multiple) {
  MemoryLeakDetector leakD;
  LStack<int> s;
  EXPECT_EQ(s.size(), 0);
  s.push(1);
  EXPECT_EQ(s.size(), 1);
  s.push(2);
  EXPECT_EQ(s.size(), 2);
  s.push(3);
  EXPECT_EQ(s.size(), 3);
  s.push(4);
  EXPECT_EQ(s.size(), 4);
  s.push(5);
  EXPECT_EQ(s.size(), 5);
  s.push(6);
  EXPECT_EQ(s.size(), 6);
}
TEST(Size, Changed) {
  MemoryLeakDetector leakD;
  LStack<int> s;
  EXPECT_EQ(s.size(), 0);
  s.push(1);
  EXPECT_EQ(s.size(), 1);
  s.push(2);
  EXPECT_EQ(s.size(), 2);
  s.push(3);
  EXPECT_EQ(s.size(), 3);
  s.peek();
  EXPECT_EQ(s.size(), 3);
  s.pop();
  EXPECT_EQ(s.size(), 2);
  s.pop();
  EXPECT_EQ(s.size(), 1);
  s.pop();
  EXPECT_EQ(s.size(), 0);
}

TEST(Stream, Empty) {
  MemoryLeakDetector leakD;
  LStack<int> s;
  std::stringstream out;
  out << s;
  EXPECT_STREQ(out.str().c_str(), "[*]");
}
TEST(Stream, One) {
  MemoryLeakDetector leakD;
  LStack<int> s;
  std::stringstream out;
  s.push(1);
  out << s;
  EXPECT_STREQ(out.str().c_str(), "[1*]");
}
TEST(Stream, More) {
  MemoryLeakDetector leakD;
  LStack<int> s;
  std::stringstream out;
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);
  s.push(5);
  s.push(6);
  out << s;
  EXPECT_STREQ(out.str().c_str(), "[1 2 3 4 5 6*]");
}
