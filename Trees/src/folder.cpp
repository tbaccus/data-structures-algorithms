#include "folder.hpp"

/**
 * @brief Construct a new Folder:: Folder object
 *
 * @param name Folder name
 */
Folder::Folder(const string name) : _name(name), parent(nullptr) {}

/**
 * @brief Construct a new Folder:: Folder object
 *
 * @param name Folder name
 * @param parent Folder parent
 */
Folder::Folder(const string name, Folder *parent)
    : _name(name), parent(parent) {}

/**
 * @brief Destroy the Folder:: Folder object
 *
 */
Folder::~Folder() { removeAll(); }

/**
 * @brief Add new subfolder to folder
 *
 * @param name Unique subfolder name
 * @return true New folder successfully created
 * @return false New folder not created, name already in use most likely
 */
bool Folder::addSubfolder(const string name) {
  Folder *newFolder = new Folder(name, this);
  const auto [it, success] = children.insert({name, newFolder});
  if (!success) delete newFolder;
  return success;
}

/**
 * @brief Remove specified subfolder if it exists
 *
 * @param name Name of subfolder to remove
 */
void Folder::removeSubfolder(const string name) {
  if (children.empty()) return;
  if (children.find(name) == children.end()) return;
  delete children[name];
  children.erase(name);
}

/**
 * @brief Remove all subfolders of specified folder
 *
 */
void Folder::removeAll() {
  if (children.empty()) return;
  for (const auto &x : children) {
    x.second->removeAll();
    delete x.second;
  }
  children.clear();
}

/**
 * @brief Get the name of the specified folder
 *
 * @return const string Name of folder
 */
const string Folder::getName() { return _name; }

/**
 * @brief Find all subfolders with the given name and return them in a vector
 *
 * @param name Name to search for
 * @return vector<Folder *> Vector of all subfolders of given name (subfolders
 * of subfolders included)
 */
vector<Folder *> Folder::find(const string name) {
  vector<Folder *> f;
  if (children.empty()) return f;
  for (const auto &x : children) {
    vector<Folder *> tmp = x.second->find(name);
    if (x.first == name) f.push_back(x.second);
    for (Folder *fold : tmp) {
      f.push_back(fold);
    }
  }
  return f;
}

/**
 * @brief Returns the number of subfolders (including sub-subfolders)
 *
 * @return size_t Number of subfolders
 */
size_t Folder::size() {
  size_t s = 0;
  if (children.empty()) return 0;
  s = children.size();
  for (const auto &x : children) {
    s += x.second->size();
  }
  return s;
}

/**
 * @brief Returns the maximum depth of the file structure
 *
 * @return size_t Maximum depth of the file structure (1 for no subfolders)
 */
size_t Folder::height() {
  if (children.empty()) return 1;
  size_t out = 1;
  for (const auto &x : children) {
    out = std::max(out, x.second->height() + 1);
  }
  return out;
}

/**
 * @brief Returns a vector of all subfolders of folder
 *
 * @return vector<Folder *> Vector of all subfolders of folder
 */
vector<Folder *> Folder::subfolders() {
  vector<Folder *> f;
  for (const auto &x : children) {
    f.push_back(x.second);
  }
  return f;
}

/**
 * @brief Returns pointer to folder above specified folder (parent folder)
 *
 * @return Folder* Pointer to parent folder
 */
Folder *Folder::superfolder() { return parent; }
