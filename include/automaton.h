//class declaration for a push down automaton

#ifndef AUTOMATON_H
#define AUTOMATON_H

#include "transition.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
#include <vector>

class Automaton {

  private:
    std::vector<std::string> alphabet;
    std::vector<std::string> states;
    std::vector<std::string> stackAlphabet;
    std::string initialState;
    std::string initialStackSymbol;
    std::vector<Transition> transitions;
    //std::vector<std::string> finalStates;

    bool trace = false;

  public:
    void loadAutomaton(std::ifstream &in);
    bool checkWord(std::string word);
    void printAutomaton();
    void setTrace(bool trace);

    Automaton () {};
    ~Automaton () {};

    Automaton (std::ifstream &in) {
      if(in.is_open()) {
        this->loadAutomaton(in);
        in.close();
      }
      else {
        std::cout << "Error opening file " << std::endl;
      }
    };

    Automaton(std::string filename) {
      std::ifstream file(filename, std::ios::in);
      if(file.is_open()) {
       this->loadAutomaton(file);
       file.close();
      }
      else {
        std::cout << "Error opening file " << filename << std::endl;
      }
    };
    
};
#endif