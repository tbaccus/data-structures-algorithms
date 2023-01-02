# Stack & Queue

1. [Stack](#stack)
2. [Queue](#queue)

***

## Stack

A list in which only the last added element can be accessed and removed.  
Functions:

* `Stack<T>()`  
  Creates a new stack.
* `push(T value)`  
  Pushes new element to top of the stack.
* `pop()` returns `T`
  Removes the top element of the stack and returns its value.
* `peek()` returns `T`  
  Returns the top element of the stack without removing it from the stack.
* `empty()` returns `bool`  
  Returns `true` if the stack is empty or `false` if not empty.
* `size()` returns `size_t`  
  Returns the number of elements in the stack.
* `operator<<`  
  Sends consise output to stream with `*` next to the accessible element.

[*Back to top*](#stack--queue)

***

## Queue

A list in which only the first added element can be accessed and removed.  
Functions:

* `Queue<T>()`  
  Creates a new queue.
* `push(T value)`  
  Pushes new element to back of the queue.
* `pop()` returns `T`
  Removes the front element of the queue and returns its value.
* `peek()` returns `T`  
  Returns the front element of the queue without removing it from the queue.
* `empty()` returns `bool`  
  Returns `true` if the queue is empty or `false` if not empty.
* `size()` returns `size_t`  
  Returns the number of elements in the queue.
* `operator<<`  
  Sends consise output to stream with `*` next to the accessible element.

[*Back to top*](#stack--queue)

***
