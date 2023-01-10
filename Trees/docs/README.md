# Trees

1. [N-Ary Tree](#n-ary-tree)
1. [Binary Search Tree](#binary-search-tree)

***

## N-Ary Tree

A tree in wich each node can have an unlimited number of children. (For sake of
learning, limited to file structure style for clear application.)  
Functions:

* `Folder(string name)`  
  Creates a new folder with given name at the root.
* `addSubfolder(string name)` returns `bool`  
  Adds new subfolder to given folder.  
  Returns `true` if subfolder is added, `false` if subfolder exists already.
* `removeSubfolder(string name)`  
  Removes subfolder of given name, if it exists.
* `removeAll()`  
  Removes all subfolders of given folder.
* `getName()` returns `string`  
  Returns the name of the given folder.
* `find(string name)` returns `std::vector<Folder*>`  
  Returns a vector of all subfolders found with the given name.
* `size()` returns `size_t`  
  Returns the number of subfolders contained in the given folder.
* `height()` returns `size_t`  
  Returns the height of the file structure.
* `subfolders()` returns `std::vector<Folder*>`  
  Returns the list of subfolders of the given folder.
* `superfolder()` returns `Folder*`  
  Returns pointer to folder that contains the given folder. If the folder is the
  root folder, returns `nullptr`.
* `operator<<`  
  Sends the list of all subfolders of the given folder.

[*Back to top*](#trees)

***

## Binary Search Tree

A tree in which each node can only have at most two children with the property that
the value of the left node is less than the parent and the value of the right node
is greater than the parent.  
Functions:

* `BST()`  
  Creates a new BST.
* `insert(int)`  
  Adds a new node to the BST.
* `search(int)` returns `bool`  
  Searches BST for value given and returns `true` if found or `false` if not.
* `remove(int)`  
  Deletes the node of the given value from the tree, if it exists.
* `inorderTraversal()` returns `std::vector<int>`  
  Traverses the BST in left-root-right order and returns a vector of the values
  in this order.
* `preorderTraversal()` returns `std::vector<int>`  
  Traverses the BST in root-left-right order and returns a vector of the values
  in this order.
* `postorderTraversal()` returns `std::vector<int>`  
  Traverses the BST in left-right-root order and returns a vector of the values
  in this order.
* `min()` returns `int`  
  Returns the smallest value of the BST.
* `max()` returns `int`  
  Returns the largest value of the BST.
* `successor(int)` returns `int`  
  Returns the closest larger value to the value given.  
  Example: 2, 1, 3, 5, 4 in tree. `predecessor(3)` run. 4 returned.
* `predecessor(int)` returns `int`  
  Returns the closest smaller value to the value given.  
  Example: 2, 1, 3, 5, 4 in tree. `predecessor(3)` run. 2 returned.

[*Back to top*](#trees)

***
