#pragma once

#include <vector>

using std::vector;

struct BSTNode {
  int value;
  BSTNode* left;
  BSTNode* right;
};

class BST {
 private:
  size_t _size;
  BSTNode* root;

 public:
  BST();
  ~BST();
  void insert(int value);
  bool search(int value);
  void remove(int value);
  vector<int> inorderTraversal();
  vector<int> preorderTraversal();
  vector<int> postorderTraversal();
  int min();
  int max();
  int successor(int value);
  int predecessor(int value);
};
