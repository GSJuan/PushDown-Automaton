// struct definition of a push down automaton transition
#ifndef TRANSITION_H
#define TRANSITION_H

struct Transition {
    int fromState;
    int toState;
    char input;
    char pop;
    char push[];
};

#endif