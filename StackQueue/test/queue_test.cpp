#include "queue.hpp"

#include <gtest/gtest.h>

#include "mtest.hpp"

TEST(Push, IntSingle) {
  MemoryLeakDetector leakD;
  LQueue<int> q;
  q.push(-1);
  EXPECT_EQ(q.peek(), -1);
}
TEST(Push, IntLarge) {
  MemoryLeakDetector leakD;
  LQueue<int> q;
  for (int i = -1'000'000; i < 1'000'000; i++) {
    q.push(i);
    ASSERT_EQ(q.peek(), -1'000'000);
  }
}
TEST(Push, DoubleSingle) {
  MemoryLeakDetector leakD;
  LQueue<double> q;
  q.push(-1.1);
  EXPECT_EQ(q.peek(), -1.1);
}
TEST(Push, DoubleLarge) {
  MemoryLeakDetector leakD;
  LQueue<double> q;
  for (int i = -1'000'000; i < 1'000'000; i++) {
    q.push(i / 100.0);
    ASSERT_EQ(q.peek(), -10'000.0);
  }
}
TEST(Push, VectorSingle) {
  MemoryLeakDetector leakD;
  LQueue<std::vector<int>> q;
  std::vector<int> n(10, 0);
  q.push(n);
  EXPECT_EQ(q.peek(), n);
}
TEST(Push, VectorLarge) {
  MemoryLeakDetector leakD;
  LQueue<std::vector<int>> q;
  for (int i = -5'000; i < 5'000; i++) {
    std::vector<int> n(50, i);
    q.push(n);
    ASSERT_EQ(q.peek()[0], -5'000);
  }
}

TEST(Pop, OOB) {
  MemoryLeakDetector leakD;
  LQueue<int> q;
  EXPECT_THROW(q.pop(), std::out_of_range);
}
TEST(Pop, Single) {
  MemoryLeakDetector leakD;
  LQueue<int> q;
  q.push(1);
  EXPECT_EQ(q.pop(), 1);
  EXPECT_THROW(q.pop(), std::out_of_range);
}
TEST(Pop, Multiple) {
  MemoryLeakDetector leakD;
  LQueue<int> q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  EXPECT_EQ(q.pop(), 1);
  EXPECT_EQ(q.pop(), 2);
  EXPECT_EQ(q.pop(), 3);
  EXPECT_EQ(q.pop(), 4);
  EXPECT_THROW(q.pop(), std::out_of_range);
}
TEST(Pop, Empty) {
  MemoryLeakDetector leakD;
  LQueue<int> q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  EXPECT_EQ(q.pop(), 1);
  EXPECT_EQ(q.pop(), 2);
  EXPECT_EQ(q.pop(), 3);
  EXPECT_EQ(q.pop(), 4);
  q.push(5);
  EXPECT_EQ(q.pop(), 5);
  EXPECT_THROW(q.pop(), std::out_of_range);
}

TEST(Peek, OOB) {
  MemoryLeakDetector leakD;
  LQueue<int> q;
  EXPECT_THROW(q.peek(), std::out_of_range);
}
TEST(Peek, Single) {
  MemoryLeakDetector leakD;
  LQueue<int> q;
  q.push(1);
  EXPECT_EQ(q.peek(), 1);
}
TEST(Peek, Multiple) {
  MemoryLeakDetector leakD;
  LQueue<int> q;
  q.push(1);
  EXPECT_EQ(q.peek(), 1);
  q.push(2);
  EXPECT_EQ(q.peek(), 1);
  q.push(3);
  q.push(4);
  EXPECT_EQ(q.peek(), 1);
  EXPECT_EQ(q.peek(), 1);
  q.pop();
  EXPECT_EQ(q.peek(), 2);
  EXPECT_EQ(q.peek(), 2);
}

TEST(Empty, Empty) {
  MemoryLeakDetector leakD;
  LQueue<int> q;
  EXPECT_TRUE(q.empty());
}
TEST(Empty, NotEmpty) {
  MemoryLeakDetector leakD;
  LQueue<int> q;
  q.push(1);
  EXPECT_FALSE(q.empty());
}
TEST(Empty, Changed) {
  MemoryLeakDetector leakD;
  LQueue<int> q;
  q.push(1);
  ASSERT_FALSE(q.empty());
  q.pop();
  EXPECT_TRUE(q.empty());
  q.push(2);
  EXPECT_FALSE(q.empty());
}

TEST(Size, Zero) {
  MemoryLeakDetector leakD;
  LQueue<int> q;
  EXPECT_EQ(q.size(), 0);
}
TEST(Size, Multiple) {
  MemoryLeakDetector leakD;
  LQueue<int> q;
  EXPECT_EQ(q.size(), 0);
  q.push(1);
  EXPECT_EQ(q.size(), 1);
  q.push(2);
  EXPECT_EQ(q.size(), 2);
  q.push(3);
  EXPECT_EQ(q.size(), 3);
  q.push(4);
  EXPECT_EQ(q.size(), 4);
  q.push(5);
  EXPECT_EQ(q.size(), 5);
  q.push(6);
  EXPECT_EQ(q.size(), 6);
}
TEST(Size, Changed) {
  MemoryLeakDetector leakD;
  LQueue<int> q;
  EXPECT_EQ(q.size(), 0);
  q.push(1);
  EXPECT_EQ(q.size(), 1);
  q.push(2);
  EXPECT_EQ(q.size(), 2);
  q.push(3);
  EXPECT_EQ(q.size(), 3);
  q.peek();
  EXPECT_EQ(q.size(), 3);
  q.pop();
  EXPECT_EQ(q.size(), 2);
  q.pop();
  EXPECT_EQ(q.size(), 1);
  q.pop();
  EXPECT_EQ(q.size(), 0);
}

TEST(Stream, Empty) {
  MemoryLeakDetector leakD;
  LQueue<int> q;
  std::stringstream out;
  out << q;
  EXPECT_STREQ(out.str().c_str(), "[*]");
}
TEST(Stream, One) {
  MemoryLeakDetector leakD;
  LQueue<int> q;
  std::stringstream out;
  q.push(1);
  out << q;
  EXPECT_STREQ(out.str().c_str(), "[*1]");
}
TEST(Stream, More) {
  MemoryLeakDetector leakD;
  LQueue<int> q;
  std::stringstream out;
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  q.push(5);
  q.push(6);
  out << q;
  EXPECT_STREQ(out.str().c_str(), "[*1 2 3 4 5 6]");
}
