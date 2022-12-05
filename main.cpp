#include <iostream>
#include "automaton.h"
int main(int argc, char *argv[]) {

  if(argc <= 2) {
    std::cout << "Usage: " << argv[0] << " -f <filename inside test directory>  [-t] (optional parameter to indicate trace. False by default, true if given)" << std::endl;
    return 1;
  }

  std::string path = TEST_RESOURCE_DIR;
  path += argv[2];

  bool trace = false;
  if(argc == 4) {
    std::string trace_str = argv[3];
    if(trace_str == "-t") {
      trace = true;
    }
  }
  
  Automaton automaton(path);
  automaton.setTrace(trace);

  while (true) {
    std::string input;
    std::cout << "If you want to EXIT, type 'exit()'" << std::endl;
    std::cout << "If you want to clear the screen, type 'clear()'" << std::endl;
    std::cout << "If you want to TOGGLE the trace option, type 'trace()'" << std::endl;
    std::cout << "Enter input word: ";
    std::cin >> input;

    if(input == "" || input == " ") {
      std::cout << "Empty input" << std::endl;
      continue;
    } else if (input == "exit()") {
      std::cout << "Exiting..." << std::endl;
      break;
    } else if(input == "trace()") {
      trace = !trace;
      automaton.setTrace(trace);
      std::cout << "Trace option is now " << (trace ? "ON" : "OFF") << std::endl << std::endl;
    } else if(input == "clear()") {
      system("clear");
    } else {
      if(automaton.checkWord(input)) {
        std::cout << "Word Accepted!" << std::endl << std::endl;
      } else {
        std::cout << "Word Rejected!" << std::endl << std::endl;
      }
      automaton.initialize();
    } 
  }

  return 0;
}