# Trees

1. [N-Ary Tree](#n-ary-tree)

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
