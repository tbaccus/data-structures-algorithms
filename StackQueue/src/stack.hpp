#pragma once

#include <sstream>
#include <vector>
using std::vector;

/**
 * @brief Stack data structure using vector for efficient data store and access
 *
 * @tparam T Data type for stack
 */
template <typename T>
class LStack {
 private:
  vector<T> s;

 public:
  void push(T value);
  T pop();
  T peek();
  bool empty();
  size_t size();
  friend std::ostream& operator<<(std::ostream& os, const LStack<T>& f) {
    vector<T> v = f.s;
    os << "[";
    for (int i = 0; i < (int)(v.size()) - 1; i++) {
      os << v[i] << " ";
    }
    if (!v.empty()) os << v.back();
    os << "*]";
    return os;
  }
};

/**
 * @brief Pushes value to top of the stack
 *
 * @tparam T Data type of stack
 * @param value Value to push
 */
template <typename T>
void LStack<T>::push(T value) {
  s.push_back(value);
}

/**
 * @brief Removes and returns the top element of the stack
 * Throws std::out_of_range if stack is empty.
 *
 * @tparam T Data type of stack
 * @return T Value of top element
 */
template <typename T>
T LStack<T>::pop() {
  if (s.empty()) throw std::out_of_range("Stack is empty, nothing to pop");
  T out = s.back();
  s.pop_back();
  return out;
}

/**
 * @brief Returns the top element of the stack without removing it
 * Throws std::out_of_range if stack is empty.
 *
 * @tparam T Data type of stack
 * @return T Value of top element
 */
template <typename T>
T LStack<T>::peek() {
  if (s.empty()) throw std::out_of_range("Stack is empty, nothing to peek");
  return s.back();
}

/**
 * @brief Returns if the stack is empty or not
 *
 * @tparam T Data type of stack
 * @return true Stack is empty
 * @return false Stack is not empty
 */
template <typename T>
bool LStack<T>::empty() {
  return s.empty();
}

/**
 * @brief Returns the number of elements in the stack
 *
 * @tparam T Data type of stack
 * @return size_t Number of elements in the stack
 */
template <typename T>
size_t LStack<T>::size() {
  return s.size();
}