/**
 * @file automaton.h
 * @author Juan García Santos (alu0101325583@ull.edu.es)
 * @brief class declaration for a push down automaton
 * @version 0.1
 * @date 2022-05-12
 * SUBJECT: CC
 * PRACTICE: 1
 * 
 * @copyright Copyright (c) 2022
 * 
 */

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
    std::string currentState;
    std::string initialStackSymbol;
    std::vector<Transition> transitions;

    std::stack<std::string> *stack;
    bool trace = false;

  public:

    //automaton memory management
    void loadAutomaton(std::ifstream &in);
    void checkAutomaton();
    void initializeStack();
    void initialize() {
      initializeStack();
      currentState = initialState;
    }

    //automaton execution
    std::vector<Transition> getPossibleTransitions(std::string state, std::string input, std::string stackSymbol);
    bool checkWord(std::string word, int wordIndex); 
    bool checkWord(std::string word) {
      return checkWord(word, 0);
    }   

    //automaton miscellaneous
    std::ostream& write(std::ostream& os);
    void setTrace(bool trace);

    //Constructors
    Automaton () {};
    Automaton (std::ifstream &file);
    Automaton(std::string filename);

    //Destructor
    ~Automaton () {};  
};
#endif