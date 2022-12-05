#include <iostream>
#include "automaton.h"
int main() {
  std::string path = TEST_RESOURCE_DIR;
  path += "APv-3.txt";
  Automaton automaton(path);

  automaton.write(std::cout);

  return 0;
}