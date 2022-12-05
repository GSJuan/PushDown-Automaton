// struct definition of a push down automaton transition
#ifndef TRANSITION_H
#define TRANSITION_H

#include <string>
#include <iostream>

struct Transition {
    std::string fromState;
    std::string toState;
    std::string input;
    std::string pop;
    std::string push;

    Transition (std::string fromState, std::string input, std::string pop, std::string toState, std::string push) {
        this->fromState = fromState;
        this->toState = toState;
        this->input = input;
        this->pop = pop;
        this->push = push;
    }

    friend std::ostream& operator<<(std::ostream& os, const Transition& transition) {
      os << "(" << transition.fromState << ", " << transition.input  << ", " << transition.pop << " ) -> (" << transition.toState  << ", " << transition.push << ")";
      return os;
    }
};

#endif