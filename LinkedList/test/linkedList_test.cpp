#include "linkedList.hpp"

#include <gtest/gtest.h>

TEST(Data, Empty) {
  LinkedList<int> tst;
  EXPECT_EQ(tst.data(), nullptr);
}
TEST(Data, Node1) {
  LinkedList<int> tst;
  tst.push(1);
  EXPECT_EQ(tst.data()->data, 1);
}
TEST(Data, Node2) {
  LinkedList<int> tst;
  tst.push(1);
  tst.push(2);
  EXPECT_EQ(tst.data()->data, 1);
  EXPECT_EQ(tst.data()->next->data, 2);
}

TEST(Push, Ints) {
  LinkedList<int> tst;
  tst.push(1);
  tst.push(2);
  tst.push(3);
  Node<int>* ptr = tst.data();
  ASSERT_NE(ptr, nullptr);
  EXPECT_EQ(ptr->data, 1);
  ptr = ptr->next;
  ASSERT_NE(ptr, nullptr);
  EXPECT_EQ(ptr->data, 2);
  ptr = ptr->next;
  ASSERT_NE(ptr, nullptr);
  EXPECT_EQ(ptr->data, 3);
  EXPECT_EQ(ptr->next, nullptr);
}
TEST(Push, Doubles) {
  LinkedList<double> tst;
  tst.push(1.1);
  tst.push(2.2);
  tst.push(3.3);
  Node<double>* ptr = tst.data();
  ASSERT_NE(ptr, nullptr);
  EXPECT_EQ(ptr->data, 1.1);
  ptr = ptr->next;
  ASSERT_NE(ptr, nullptr);
  EXPECT_EQ(ptr->data, 2.2);
  ptr = ptr->next;
  ASSERT_NE(ptr, nullptr);
  EXPECT_EQ(ptr->data, 3.3);
  EXPECT_EQ(ptr->next, nullptr);
}
TEST(Push, Vectors) {
  LinkedList<std::vector<int>> tst;
  tst.push(std::vector<int>(1, 1));
  tst.push(std::vector<int>(2, 2));
  tst.push(std::vector<int>(3, 3));
  Node<std::vector<int>>* ptr = tst.data();
  ASSERT_NE(ptr, nullptr);
  EXPECT_EQ(ptr->data.size(), 1);
  ptr = ptr->next;
  ASSERT_NE(ptr, nullptr);
  EXPECT_EQ(ptr->data.size(), 2);
  ptr = ptr->next;
  ASSERT_NE(ptr, nullptr);
  EXPECT_EQ(ptr->data.size(), 3);
  EXPECT_EQ(ptr->next, nullptr);
}

TEST(Insert, Beginning) {
  LinkedList<int> tst;
  tst.push(1);                    // 1
  tst.push(2);                    // 1 2
  tst.push(3);                    // 1 2 3
  EXPECT_TRUE(tst.insert(0, 4));  // 4 1 2 3

  Node<int>* ptr = tst.data();
  ASSERT_NE(ptr, nullptr);
  EXPECT_EQ(ptr->data, 4);
  ptr = ptr->next;
  ASSERT_NE(ptr, nullptr);
  EXPECT_EQ(ptr->data, 1);
  ptr = ptr->next;
  ASSERT_NE(ptr, nullptr);
  EXPECT_EQ(ptr->data, 2);
  ptr = ptr->next;
  ASSERT_NE(ptr, nullptr);
  EXPECT_EQ(ptr->data, 3);
  EXPECT_EQ(ptr->next, nullptr);
}
TEST(Insert, Middle) {
  LinkedList<int> tst;
  tst.push(1);                    // 1
  tst.push(2);                    // 1 2
  tst.push(3);                    // 1 2 3
  EXPECT_TRUE(tst.insert(1, 4));  // 1 4 2 3

  Node<int>* ptr = tst.data();
  ASSERT_NE(ptr, nullptr);
  EXPECT_EQ(ptr->data, 1);
  ptr = ptr->next;
  ASSERT_NE(ptr, nullptr);
  EXPECT_EQ(ptr->data, 4);
  ptr = ptr->next;
  ASSERT_NE(ptr, nullptr);
  EXPECT_EQ(ptr->data, 2);
  ptr = ptr->next;
  ASSERT_NE(ptr, nullptr);
  EXPECT_EQ(ptr->data, 3);
  EXPECT_EQ(ptr->next, nullptr);
}
TEST(Insert, End) {
  LinkedList<int> tst;
  tst.push(1);                    // 1
  tst.push(2);                    // 1 2
  tst.push(3);                    // 1 2 3
  EXPECT_TRUE(tst.insert(3, 4));  // 1 2 3 4

  Node<int>* ptr = tst.data();
  ASSERT_NE(ptr, nullptr);
  EXPECT_EQ(ptr->data, 1);
  ptr = ptr->next;
  ASSERT_NE(ptr, nullptr);
  EXPECT_EQ(ptr->data, 2);
  ptr = ptr->next;
  ASSERT_NE(ptr, nullptr);
  EXPECT_EQ(ptr->data, 3);
  ptr = ptr->next;
  ASSERT_NE(ptr, nullptr);
  EXPECT_EQ(ptr->data, 4);
  EXPECT_EQ(ptr->next, nullptr);
}
TEST(Insert, OOB) {
  LinkedList<int> tst;
  tst.push(1);                     // 1
  tst.push(2);                     // 1 2
  tst.push(3);                     // 1 2 3
  EXPECT_FALSE(tst.insert(8, 4));  // 1 2 3

  Node<int>* ptr = tst.data();
  ASSERT_NE(ptr, nullptr);
  EXPECT_EQ(ptr->data, 1);
  ptr = ptr->next;
  ASSERT_NE(ptr, nullptr);
  EXPECT_EQ(ptr->data, 2);
  ptr = ptr->next;
  ASSERT_NE(ptr, nullptr);
  EXPECT_EQ(ptr->data, 3);
  EXPECT_EQ(ptr->next, nullptr);
}
TEST(Insert, Empty) {
  LinkedList<int> tst;
  EXPECT_TRUE(tst.insert(0, 1));  // 1
  EXPECT_TRUE(tst.insert(0, 2));  // 2 1
  EXPECT_TRUE(tst.insert(1, 3));  // 2 3 1
  EXPECT_TRUE(tst.insert(3, 4));  // 2 3 1 4

  Node<int>* ptr = tst.data();
  ASSERT_NE(ptr, nullptr);
  EXPECT_EQ(ptr->data, 2);
  ptr = ptr->next;
  ASSERT_NE(ptr, nullptr);
  EXPECT_EQ(ptr->data, 3);
  ptr = ptr->next;
  ASSERT_NE(ptr, nullptr);
  EXPECT_EQ(ptr->data, 1);
  ptr = ptr->next;
  ASSERT_NE(ptr, nullptr);
  EXPECT_EQ(ptr->data, 4);
  EXPECT_EQ(ptr->next, nullptr);
}

TEST(Get, OOB) {
  LinkedList<int> tst;
  EXPECT_THROW(tst.get(0), std::out_of_range);
  tst.push(0);
  EXPECT_THROW(tst.get(1), std::out_of_range);
}
TEST(Get, InBounds) {
  LinkedList<int> tst;
  tst.push(0);
  tst.push(1);
  tst.push(2);
  ASSERT_NO_THROW(tst.get(0));
  ASSERT_NO_THROW(tst.get(1));
  ASSERT_NO_THROW(tst.get(2));
  EXPECT_EQ(tst.get(0), 0);
  EXPECT_EQ(tst.get(1), 1);
  EXPECT_EQ(tst.get(2), 2);
}

TEST(GetOp, OOB) {
  LinkedList<int> tst;
  EXPECT_THROW(tst[0], std::out_of_range);
  tst.push(0);
  EXPECT_THROW(tst[1], std::out_of_range);
}
TEST(GetOp, InBounds) {
  LinkedList<int> tst;
  tst.push(0);
  tst.push(1);
  tst.push(2);
  ASSERT_NO_THROW(tst[0]);
  ASSERT_NO_THROW(tst[1]);
  ASSERT_NO_THROW(tst[2]);
  EXPECT_EQ(tst[0], 0);
  EXPECT_EQ(tst[1], 1);
  EXPECT_EQ(tst[2], 2);
}

TEST(Erase, Empty) {
  LinkedList<int> tst;
  EXPECT_THROW(tst.erase(0), std::out_of_range);
}
TEST(Erase, Node1) {
  LinkedList<int> tst;
  tst.push(1);
  EXPECT_NO_THROW(tst.erase(0));
  EXPECT_EQ(tst.data(), nullptr);
}
TEST(Erase, Node2) {
  LinkedList<int> tst;
  tst.push(1);
  tst.push(2);
  EXPECT_NO_THROW(tst.erase(0));
  EXPECT_EQ(tst[0], 2);
}
TEST(Erase, Node2_1) {
  LinkedList<int> tst;
  tst.push(1);
  EXPECT_NO_THROW(tst.erase(0));
  EXPECT_EQ(tst.data(), nullptr);
  tst.push(2);
  EXPECT_EQ(tst[0], 2);
}
TEST(Erase, Middle) {
  LinkedList<int> tst;
  tst.push(1);
  tst.push(2);
  tst.push(3);
  EXPECT_NO_THROW(tst.erase(1));
  EXPECT_EQ(tst[0], 1);
  EXPECT_EQ(tst[1], 3);
  EXPECT_THROW(tst[2], std::out_of_range);
}
TEST(Erase, End) {
  LinkedList<int> tst;
  tst.push(1);
  tst.push(2);
  tst.push(3);
  EXPECT_NO_THROW(tst.erase(2));
  EXPECT_EQ(tst[0], 1);
  EXPECT_EQ(tst[1], 2);
  EXPECT_THROW(tst[2], std::out_of_range);
}

TEST(Pop, Empty) {
  LinkedList<int> tst;
  EXPECT_THROW(tst.pop(), std::out_of_range);
}
TEST(Pop, Node1) {
  LinkedList<int> tst;
  tst.push(1);
  EXPECT_EQ(tst.pop(), 1);
  EXPECT_EQ(tst.data(), nullptr);
}
TEST(Pop, Node2) {
  LinkedList<int> tst;
  tst.push(1);
  tst.push(2);
  EXPECT_EQ(tst.pop(), 2);
  EXPECT_EQ(tst[0], 1);
}
TEST(Pop, Node2_1) {
  LinkedList<int> tst;
  tst.push(1);
  EXPECT_EQ(tst.pop(), 1);
  EXPECT_EQ(tst.data(), nullptr);
  tst.push(2);
  EXPECT_EQ(tst[0], 2);
}

TEST(Clear, Empty) {
  LinkedList<int> tst;
  EXPECT_NO_THROW(tst.clear());
  EXPECT_TRUE(tst.empty());
}
TEST(Clear, NotEmpty) {
  LinkedList<int> tst;
  tst.push(1);
  tst.push(2);
  EXPECT_NO_THROW(tst.clear());
  EXPECT_TRUE(tst.empty());
}
TEST(Clear, DoubleClear) {
  LinkedList<int> tst;
  tst.push(1);
  tst.push(2);
  EXPECT_NO_THROW(tst.clear());
  EXPECT_TRUE(tst.empty());
  EXPECT_NO_THROW(tst.clear());
  EXPECT_TRUE(tst.empty());
}

TEST(Front, Empty) {
  LinkedList<int> tst;
  EXPECT_THROW(tst.front(), std::out_of_range);
}
TEST(Front, Push) {
  LinkedList<int> tst;
  tst.push(1);  // 1
  EXPECT_EQ(tst.front(), 1);
  tst.push(2);  // 1 2
  EXPECT_EQ(tst.front(), 1);
}
TEST(Front, Insert) {
  LinkedList<int> tst;
  tst.insert(0, 1);  // 1
  EXPECT_EQ(tst.front(), 1);
  tst.insert(0, 2);  // 2 1
  EXPECT_EQ(tst.front(), 2);
  tst.insert(1, 3);  // 2 3 1
  EXPECT_EQ(tst.front(), 2);
}
TEST(Front, Erase) {
  LinkedList<int> tst;
  tst.push(1);   // 1
  tst.push(2);   // 1 2
  tst.push(3);   // 1 2 3
  tst.erase(0);  // 2 3
  EXPECT_EQ(tst.front(), 2);
  tst.erase(1);  // 2
  EXPECT_EQ(tst.front(), 2);
}
TEST(Front, Pop) {
  LinkedList<int> tst;
  tst.push(1);  // 1
  tst.push(2);  // 1 2
  tst.pop();    // 1
  EXPECT_EQ(tst.front(), 1);
}
TEST(Front, Clear) {
  LinkedList<int> tst;
  tst.push(1);  // 1
  tst.push(2);  // 1 2
  tst.clear();  // *
  EXPECT_THROW(tst.front(), std::out_of_range);
}

TEST(Back, Empty) {
  LinkedList<int> tst;
  EXPECT_THROW(tst.back(), std::out_of_range);
}
TEST(Back, Push) {
  LinkedList<int> tst;
  tst.push(1);  // 1
  EXPECT_EQ(tst.back(), 1);
  tst.push(2);  // 1 2
  EXPECT_EQ(tst.back(), 2);
}
TEST(Back, Insert) {
  LinkedList<int> tst;
  tst.insert(0, 1);  // 1
  EXPECT_EQ(tst.back(), 1);
  tst.insert(0, 2);  // 2 1
  EXPECT_EQ(tst.back(), 1);
  tst.insert(2, 3);  // 2 1 3
  EXPECT_EQ(tst.back(), 3);
}
TEST(Back, Erase) {
  LinkedList<int> tst;
  tst.push(1);   // 1
  tst.push(2);   // 1 2
  tst.push(3);   // 1 2 3
  tst.erase(0);  // 2 3
  EXPECT_EQ(tst.back(), 3);
  tst.erase(1);  // 2
  EXPECT_EQ(tst.back(), 2);
}
TEST(Back, Pop) {
  LinkedList<int> tst;
  tst.push(1);  // 1
  tst.push(2);  // 1 2
  tst.pop();    // 1
  EXPECT_EQ(tst.back(), 1);
}
TEST(Back, Clear) {
  LinkedList<int> tst;
  tst.push(1);  // 1
  tst.push(2);  // 1 2
  tst.clear();  // *
  EXPECT_THROW(tst.back(), std::out_of_range);
}

TEST(Size, Empty) {
  LinkedList<int> tst;
  EXPECT_EQ(tst.size(), 0);
}
TEST(Size, Push) {
  LinkedList<int> tst;
  tst.push(1);  // 1
  EXPECT_EQ(tst.size(), 1);
  tst.push(2);  // 1 2
  EXPECT_EQ(tst.size(), 2);
}
TEST(Size, Insert) {
  LinkedList<int> tst;
  tst.insert(0, 1);  // 1
  EXPECT_EQ(tst.size(), 1);
  tst.insert(0, 2);  // 2 1
  EXPECT_EQ(tst.size(), 2);
  tst.insert(2, 3);  // 2 1 3
  EXPECT_EQ(tst.size(), 3);
}
TEST(Size, Erase) {
  LinkedList<int> tst;
  tst.push(1);   // 1
  tst.push(2);   // 1 2
  tst.erase(0);  // 2
  EXPECT_EQ(tst.size(), 1);
  tst.erase(0);  // *
  EXPECT_EQ(tst.size(), 0);
}
TEST(Size, Pop) {
  LinkedList<int> tst;
  tst.push(1);  // 1
  tst.push(2);  // 1 2
  tst.pop();    // 1
  EXPECT_EQ(tst.size(), 1);
  tst.pop();
  EXPECT_EQ(tst.size(), 0);
}
TEST(Size, Clear) {
  LinkedList<int> tst;
  tst.push(1);  // 1
  tst.push(2);  // 1 2
  tst.clear();  // *
  EXPECT_EQ(tst.size(), 0);
}

TEST(Empty, Empty) {
  LinkedList<int> tst;
  EXPECT_TRUE(tst.empty());
}
TEST(Empty, Push) {
  LinkedList<int> tst;
  tst.push(1);  // 1
  EXPECT_FALSE(tst.empty());
  tst.push(2);  // 1 2
  EXPECT_FALSE(tst.empty());
}
TEST(Empty, Insert) {
  LinkedList<int> tst;
  tst.insert(0, 1);  // 1
  EXPECT_FALSE(tst.empty());
  tst.insert(0, 2);  // 2 1
  EXPECT_FALSE(tst.empty());
  tst.insert(2, 3);  // 2 1 3
  EXPECT_FALSE(tst.empty());
}
TEST(Empty, Erase) {
  LinkedList<int> tst;
  tst.push(1);   // 1
  tst.push(2);   // 1 2
  tst.erase(0);  // 2
  EXPECT_FALSE(tst.empty());
  tst.erase(0);  // *
  EXPECT_TRUE(tst.empty());
}
TEST(Empty, Pop) {
  LinkedList<int> tst;
  tst.push(1);  // 1
  tst.push(2);  // 1 2
  tst.pop();    // 1
  EXPECT_FALSE(tst.empty());
  tst.pop();
  EXPECT_TRUE(tst.empty());
}
TEST(Empty, Clear) {
  LinkedList<int> tst;
  tst.push(1);  // 1
  tst.push(2);  // 1 2
  tst.clear();  // *
  EXPECT_TRUE(tst.empty());
}

TEST(Stream, Empty) {
  LinkedList<int> tst;
  std::stringstream out;
  out << tst;
  EXPECT_STREQ(out.str().c_str(), "[N]");
}
TEST(Stream, Node1) {
  LinkedList<int> tst;
  std::stringstream out;
  tst.push(1);
  out << tst;
  EXPECT_STREQ(out.str().c_str(), "[1 > N]");
}
TEST(Stream, Node2) {
  LinkedList<int> tst;
  std::stringstream out;
  tst.push(1);
  tst.push(2);
  out << tst;
  EXPECT_STREQ(out.str().c_str(), "[1 > 2 > N]");
}