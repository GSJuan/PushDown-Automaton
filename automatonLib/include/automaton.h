//class declaration for a push down automaton

#ifndef AUTOMATON_H
#define AUTOMATON_H

#include "transition.h"
#include <iostream>
#include <stack>
#include <vector>

class Automaton {

  private:
    std::vector<int> states;
    std::vector<char> alphabet;
    std::vector<char> stackAlphabet;
    int initialState;
    char initialStackSymbol;
    std::vector<Transition> transitions;
    std::vector<int> finalStates;

  public:

};
#endif