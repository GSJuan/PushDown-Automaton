/**
 * @file transition.h
 * @author Juan García Santos (alu0101325583@ull.edu.es)
 * @brief struct definition of a push down automaton transition
 * @version 0.1
 * @date 2022-05-12
 * SUBJECT: CC
 * PRACTICE: 1
 * 
 * @copyright Copyright (c) 2022
 * 
 */

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