#pragma once

#include <map>
#include <sstream>
#include <vector>

using std::map;
using std::string;
using std::vector;

class Folder {
 private:
  Folder* parent;
  string _name;
  map<string, Folder*> children;

 public:
  Folder(const string name);
  Folder(const string name, Folder* parent);
  ~Folder();
  bool addSubfolder(const string name);
  void removeSubfolder(const string name);
  void removeAll();
  const string getName();
  vector<Folder*> find(const string name);
  size_t size();
  size_t height();
  vector<Folder*> subfolders();
  Folder* superfolder();
  friend std::ostream& operator<<(std::ostream& os, const Folder& f) {
    os << f._name << std::endl;
    for (const auto& x : f.children) {
      os << "\t" << x.first;
    }
    if (f.children.empty()) os << "0 subfolders";
    os << std::endl;
    return os;
  }
};
