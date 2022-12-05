#include <iostream>
#include "automaton.h"
int main() {
  std::string path = TEST_RESOURCE_DIR;
  path += "APv.txt";
  Automaton automaton(path);

  if(automaton.checkWord("ab", 0)) {
    std::cout << "Accepted" << std::endl;
  } else {
    std::cout << "Rejected" << std::endl;
  }

  return 0;
}