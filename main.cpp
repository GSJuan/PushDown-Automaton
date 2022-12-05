#include <iostream>
#include "automaton.h"
int main() {

  std::string path = TEST_RESOURCE_DIR;
  path += "APv-3.txt";

  
  Automaton automaton(path);

  automaton.setTrace(true);

  if(automaton.checkWord("abbb")) {
    std::cout << "Accepted" << std::endl;
  } else {
    std::cout << "Rejected" << std::endl;
  }

  return 0;
}