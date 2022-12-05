//class declaration for a push down automaton

#ifndef AUTOMATON_H
#define AUTOMATON_H

#include "transition.h"
#include <fstream>
#include <sstream>
#include <stack>
#include <vector>
#include <unordered_set>

class Automaton {

  private:
    std::unordered_set <std::string> alphabet;
    std::unordered_set <std::string> states;
    std::unordered_set <std::string> stackAlphabet;
    std::string initialState;
    std::string initialStackSymbol;
    std::vector<Transition> transitions;
    //std::vector<std::string> finalStates;

    bool trace = false;

  public:
    void loadAutomaton(std::ifstream &in);
    void checkAutomaton();
    bool checkWord(std::string word);
    std::ostream& write(std::ostream& os);
    void setTrace(bool trace);

    Automaton () {};
    ~Automaton () {};

    Automaton (std::ifstream &file) {
      if(!file.is_open()) {
        std::cerr << "Error opening file " << std::endl;
        exit(1);
      }

      this->loadAutomaton(file);
      file.close();
      this->checkAutomaton();
    };

    Automaton(std::string filename) {
      std::ifstream file(filename, std::ios::in);
      if(!file.is_open()) {
        std::cerr << "Error opening file " << filename << std::endl;
        exit(1);
      }

      this->loadAutomaton(file);
      file.close();
      this->checkAutomaton();
    };
    
};
#endif