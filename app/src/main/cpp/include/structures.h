#ifndef SFF_STRUCTURES_H_
#define SFF_STRUCTURES_H_

#include "HashTable.h"
#include "types.h"

const char EPS = '@';
const int NO_ID = -1;

struct Node;

struct Transition {
    Key c;
    Node* state;

    Transition(): c(EPS), state(nullptr) {}
    ~Transition() { state = nullptr; }
};

struct Node {
    int id;
    bool isTerminal;
    HashTable<Key, Transition> transitions;

    Node(): id(NO_ID), isTerminal(false), transitions() {}
};

struct NoSuchElementException {};

#endif  // SFF_STRUCTURES_H_
