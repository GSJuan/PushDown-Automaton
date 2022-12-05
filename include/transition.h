// struct definition of a push down automaton transition
#ifndef TRANSITION_H
#define TRANSITION_H

#include <string>

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
};

#endif