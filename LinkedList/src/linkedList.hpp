#pragma once

#include <iomanip>
#include <sstream>

template <typename T>
struct Node {
  T data;
  Node* next;
};

template <typename T>
class LinkedList {
 private:
  size_t length;
  Node<T>* head;
  Node<T>* tail;

 public:
  LinkedList();
  ~LinkedList();
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

  friend std::ostream& operator<<(std::ostream& os, const LinkedList<T>& f) {
    Node<T>* ptr = f.head;
    os << "[";
    while(ptr) {
      os << ptr->data << " > ";
      ptr = ptr->next;
    }
    os << "N]";
    return os;
  }
};

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr), length(0) {}

template <typename T>
LinkedList<T>::~LinkedList() {
  this->clear();
}

/**
 * @brief Pushes new node to end of list
 *
 * @tparam T Data type
 * @param value Node value
 */
template <typename T>
void LinkedList<T>::push(T value) {
  Node<T>* newNode = new Node<T>;
  newNode->data = value;
  newNode->next = nullptr;

  if (!head) head = newNode;       // List empty
  if (tail) tail->next = newNode;  // List not empty
  tail = newNode;
  length++;
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
bool LinkedList<T>::insert(unsigned int pos, T value) {
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
T LinkedList<T>::get(unsigned int pos) {
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
T LinkedList<T>::front() {
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
T LinkedList<T>::back() {
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
size_t LinkedList<T>::size() {
  // Verifies and corrects size of list before returning
  Node<T>* ptr = head;
  size_t check = 0;

  while (ptr) {
    check++;
    ptr = ptr->next;
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
Node<T>* LinkedList<T>::data() {
  return head;
}

/**
 * @brief Checks if list is empty
 *
 * @tparam T Data type
 * @return True if list is empty, false otherwise
 */
template <typename T>
bool LinkedList<T>::empty() {
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
void LinkedList<T>::erase(unsigned int pos) {
  if (pos >= length) throw std::out_of_range("Position out of range");
  Node<T>* ptr = head;
  Node<T>* ptr2 = nullptr;

  if (pos == 0) {  // Delete head node
    head = ptr->next;
    delete ptr;
    length--;
    if(length == 0) {
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
}

/**
 * @brief Deletes every node of the list
 *
 * @tparam T Data type
 */
template <typename T>
void LinkedList<T>::clear() {
  while (head) {
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
T LinkedList<T>::pop() {
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

  return val;
}

// TODO:
// template <typename T>
// friend std::ostream& LinkedList<T>::operator<<(std::ostream& os, const
// LinkedList& f) {}