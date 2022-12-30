#pragma once

#include <sstream>

template <typename T>
struct Node {
  T data;
  Node* next;
};

template <typename T>
class CircularLinkedList {
 private:
  size_t length;
  Node<T>* head;
  Node<T>* tail;

 public:
  CircularLinkedList();
  ~CircularLinkedList();
  void push(T value);
  bool insert(unsigned int pos, T value);
  T get(unsigned int pos);
  T front();
  T back();
  size_t size();
  Node<T>* data();
  bool empty();
  void erase(unsigned int pos);
  void clear();
  T pop();

  T operator[](unsigned int pos) {
    return this->get(pos);
  }

  friend std::ostream& operator<<(std::ostream& os, const CircularLinkedList<T>& f) {
    Node<T>* ptr = f.head;
    os << "[";
    while(ptr) {
      os << ptr->data << " > ";
      ptr = ptr->next;
      if(ptr == f.head) {
        os << "*";
        break;
      }
    }
    os << "]";
    return os;
  }
};

template <typename T>
CircularLinkedList<T>::CircularLinkedList() : head(nullptr), tail(nullptr), length(0) {}

template <typename T>
CircularLinkedList<T>::~CircularLinkedList() {
  this->clear();
}

/**
 * @brief Pushes new node to end of list
 *
 * @tparam T Data type
 * @param value Node value
 */
template <typename T>
void CircularLinkedList<T>::push(T value) {
  Node<T>* newNode = new Node<T>;
  newNode->data = value;
  newNode->next = nullptr;

  if (!head) head = newNode;       // List empty
  if (tail) tail->next = newNode;  // List not empty
  tail = newNode;
  length++;
  tail->next = head;
}

/**
 * @brief Inserts new node at given position
 *
 * @tparam T Data type
 * @param pos Position of new node
 * @param value Value of new node
 * @return True if successful, false if not
 */
template <typename T>
bool CircularLinkedList<T>::insert(unsigned int pos, T value) {
  if (pos > length) return false;  // Out of bounds
  if (pos == length) {             // Add to end, same as push()
    this->push(value);
    return true;
  }
  if (pos == 0) {  // New head
    Node<T>* newNode = new Node<T>;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    length++;
    tail->next = head;
    return true;
  }

  Node<T>* ptr = head;
  Node<T>* newNode = new Node<T>;
  newNode->data = value;
  length++;

  for (int i = 0; i < pos - 1; i++) {
    ptr = ptr->next;
  }

  newNode->next = ptr->next;
  ptr->next = newNode;
  return true;
}

/**
 * @brief Get the value of the node at the given position
 *
 * @tparam T Data type
 * @param pos Node position
 * @return Found node value
 */
template <typename T>
T CircularLinkedList<T>::get(unsigned int pos) {
  if (pos >= length) throw std::out_of_range("Position out of range");

  Node<T>* ptr = head;

  for (int i = 0; i < pos; i++) {
    ptr = ptr->next;
  }

  return ptr->data;
}

/**
 * @brief Gets the value of the first node of the list
 *
 * @tparam T Data type
 * @return Value of first node
 */
template <typename T>
T CircularLinkedList<T>::front() {
  if (!head) throw std::out_of_range("List has no front node");
  return head->data;
}

/**
 * @brief Gets value of the last node of the list
 *
 * @tparam T Data type
 * @return Value of last node
 */
template <typename T>
T CircularLinkedList<T>::back() {
  if (!tail) throw std::out_of_range("List has no back node");
  return tail->data;
}

/**
 * @brief Returns the size of the list
 *
 * @tparam T Data type
 * @return The size of the list
 */
template <typename T>
size_t CircularLinkedList<T>::size() {
  // Verifies and corrects size of list before returning
  Node<T>* ptr = head;
  size_t check = 0;

  while (ptr) {
    check++;
    ptr = ptr->next;
    if(ptr == head) break;
  }

  if (check > length) length = check;
  return length;
}

/**
 * @brief Returns pointer to head node for direct data access
 *
 * @tparam T Data type
 * @return Pointer to head
 */
template <typename T>
Node<T>* CircularLinkedList<T>::data() {
  return head;
}

/**
 * @brief Checks if list is empty
 *
 * @tparam T Data type
 * @return True if list is empty, false otherwise
 */
template <typename T>
bool CircularLinkedList<T>::empty() {
  if (!head) return true;
  return false;
}

/**
 * @brief Removes node at given position
 *
 * @tparam T Data type
 * @param pos Position of node to remove
 */
template <typename T>
void CircularLinkedList<T>::erase(unsigned int pos) {
  if (pos >= length) throw std::out_of_range("Position out of range");
  Node<T>* ptr = head;
  Node<T>* ptr2 = nullptr;

  if (pos == 0) {  // Delete head node
    head = head->next;
    delete ptr;
    length--;
    tail->next = head;
    if(length == 0) {
      head = nullptr;
      tail = nullptr;
    }
    return;
  }

  // Point to node previous to position
  for (int i = 0; i < pos - 1; i++) {
    ptr = ptr->next;
  }

  if (pos == length - 1) tail = ptr;
  ptr2 = ptr->next->next;
  delete ptr->next;
  length--;
  ptr->next = ptr2;
  tail->next = head;
}

/**
 * @brief Deletes every node of the list
 *
 * @tparam T Data type
 */
template <typename T>
void CircularLinkedList<T>::clear() {
  for (int i = 0; i < length; i++) {
    tail = head->next;
    delete head;
    head = tail;
  }
  head = nullptr;
  tail = nullptr;
  length = 0;
}

/**
 * @brief Removes last node and returns its value
 *
 * @tparam T Data type
 * @return T Value of node removed
 */
template <typename T>
T CircularLinkedList<T>::pop() {
  if (length == 0) throw std::out_of_range("No node to pop");
  if (length == 1) { // Only 1 node in list
    T val = head->data;
    delete head;
    length--;
    head = nullptr;
    tail = nullptr;
    return val;
  }

  Node<T>* ptr = head;

  // Point to node previous to last
  for (int i = 0; i < length - 2; i++) {
    ptr = ptr->next;
  }

  T val = ptr->next->data;

  tail = ptr;
  delete ptr->next;
  length--;
  ptr->next = nullptr;
  tail->next = head;

  return val;
}