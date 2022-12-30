# Linked List

1. [Singly Linked List](#singly-linked-list)
2. [Circularly Linked list](#circular-linked-list)

***

## Singly Linked List

A list of nodes linked only together with the next node in the list.  
Functions:

* `LinkedList<T>()`  
  Creates a new linked list.
* `push(int value)`  
  Pushes new element to end of list.
* `insert(int pos, T value)` returns `bool`
  Adds new node with given value at position given.  
  Returns `true` if successful or `false` if not.
* `get(int pos)` returns `T`  
  Returns the value of the node at the position with type T. If the position goes out of bounds, gives out of bound error.
* `front()` returns `T`  
  Returns the value of the node at the first position. If there is no first node, gives out of bound error.
* `back()` returns `T`  
  Returns the value of the node at the last position. If there is no last node, gives out of bound error.
* `size()` returns `size_t`  
  Returns the number of nodes in the list.
* `data()` returns `Node<T>*`  
  Returns the pointer to the head of the list for direct node access.
* `empty()` returns `bool`  
  Returns `true` if list is empty or `false` if not.
* `erase(int pos)`
  Removes element from list at given position.
* `clear()`  
  Removes all elements of the list.
* `pop()` returns `T`  
  Removes and returns the value of the last node of the list.
* `operator[]` returns `T`  
  Returns the value of the node at the position with type T. If the position goes out of bounds, gives out of bound error.
* `operator<<`  
  Sends consise output to stream.

[*Back to top*](#linked-list)

***

## Circular Linked List

A list of nodes linked only together with the next node in the list. Last node is linked to the first.  
Functions:

* `LinkedList<T>()`  
  Creates a new linked list.
* `push(int value)`  
  Pushes new element to end of list.
* `insert(int pos, T value)` returns `bool`
  Adds new node with given value at position given.  
  Returns `true` if successful or `false` if not (generally out of bounds of list).
* `get(int pos)` returns `T`  
  Returns the value of the node at the position with type T. If the position goes out of bounds, gives out of bound error.
* `front()` returns `T`  
  Returns the value of the node at the first position. If there is no first node, gives out of bound error.
* `back()` returns `T`  
  Returns the value of the node at the last position. If there is no last node, gives out of bound error.
* `size()` returns `size_t`  
  Returns the number of nodes in the list.
* `data()` returns `Node<T>*`  
  Returns the pointer to the head of the list for direct node access.
* `empty()` returns `bool`  
  Returns `true` if list is empty or `false` if not.
* `erase(int pos)`
  Removes element from list at given position.
* `clear()`  
  Removes all elements of the list.
* `pop()` returns `T`  
  Removes and returns the value of the last node of the list.
* `operator[]` returns `T`  
  Returns the value of the node at the position with type T. If the position goes out of bounds, gives out of bound error.
* `operator<<`  
  Sends consise output to stream.

[*Back to top*](#linked-list)

***
