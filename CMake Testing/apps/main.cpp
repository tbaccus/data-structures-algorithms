#include <iostream>

#include "hello.h"

using std::cout;
using std::endl;
using std::string;

int main(int, char**) {
  string helloJim = generateHelloString("Jim");
  cout << helloJim << endl;

  return 0;
}