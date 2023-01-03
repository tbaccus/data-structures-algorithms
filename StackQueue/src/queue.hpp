#pragma once

#include <sstream>

template <typename T>
struct QNode {
  T _value;
  QNode* next;
  QNode(T value) : _value(value), next(nullptr) {}
};

/**
 * @brief Queue data structure using linked list for efficient data access
 *
 * @tparam T Data type for queue
 */
template <typename T>
class LQueue {
 private:
  QNode<T>* head;
  QNode<T>* tail;
  size_t _size;

 public:
  LQueue() : _size(0), head(nullptr), tail(nullptr) {}
  ~LQueue();
  void push(T value);
  T pop();
  T peek();
  bool empty();
  size_t size();
  friend std::ostream& operator<<(std::ostream& os, const LQueue<T>& f) {
    if (!f.head) {
      os << "[*]";
      return os;
    }
    os << "[*";
    QNode<T>* i;
    for (i = f.head; i->next != nullptr; i = i->next) {
      os << i->_value << " ";
    }
    os << i->_value;
    os << "]";
    return os;
  }
};

/**
 * @brief Destroy the LQueue
 *
 * @tparam T Data type of queue
 */
template <typename T>
LQueue<T>::~LQueue() {
  while (head) {
    tail = head;
    head = head->next;
    delete tail;
  }
}

/**
 * @brief Pushes value to back of the queue
 *
 * @tparam T Data type of queue
 * @param value Value to push
 */
template <typename T>
void LQueue<T>::push(T value) {
  QNode<T>* newNode = new QNode<T>(value);
  if (tail) tail->next = newNode;
  tail = newNode;
  if (!head) head = newNode;
  _size++;
}

/**
 * @brief Removes and returns the front element of the queue
 * Throws std::out_of_range if queue is empty.
 *
 * @tparam T Data type of queue
 * @return T Value of front element
 */
template <typename T>
T LQueue<T>::pop() {
  if (_size == 0) throw std::out_of_range("Queue is empty, nothing to pop");
  T out = head->_value;
  QNode<T>* tmp = head->next;
  delete head;
  head = tmp;
  if (!head) tail = nullptr;
  _size--;
  return out;
}

/**
 * @brief Returns the front element of the queue without removing it
 * Throws std::out_of_range if queue is empty.
 *
 * @tparam T Data type of queue
 * @return T Value of front element
 */
template <typename T>
T LQueue<T>::peek() {
  if (_size == 0) throw std::out_of_range("Queue is empty, nothing to peek");
  return head->_value;
}

/**
 * @brief Returns if the queue is empty or not
 *
 * @tparam T Data type of queue
 * @return true Queue is empty
 * @return false Queue is not empty
 */
template <typename T>
bool LQueue<T>::empty() {
  return (_size == 0);
}

/**
 * @brief Returns the number of elements in the queue
 *
 * @tparam T Data type of queue
 * @return size_t Number of elements in the queue
 */
template <typename T>
size_t LQueue<T>::size() {
  return _size;
}