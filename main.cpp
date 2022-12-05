#include <iostream>
#include "automaton.h"
int main() {
  std::string path = TEST_RESOURCE_DIR;
  path += "APv.txt";
  Automaton automaton(path);
  return 0;
}