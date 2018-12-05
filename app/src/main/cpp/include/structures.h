#ifndef SFF_STRUCTURES_H_
#define SFF_STRUCTURES_H_

#include "Vector.h"

const char EPS = '@';
const int NO_ID = -1;

struct Node;

struct Transition {
    char c;
    Node* state;

    Transition(): c(EPS), state(nullptr) {}
    ~Transition() { state = nullptr; }
};

struct Node {
    int id;
    bool isTerminal;
    Vector<Transition> transitions;

    Node(): id(NO_ID), isTerminal(false), transitions() {}
};

#endif  // SFF_STRUCTURES_H_
