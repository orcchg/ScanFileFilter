#ifndef SFF_AUTOMATON_H_
#define SFF_AUTOMATON_H_

#include "structures.h"

class Automaton final {
public:
    Automaton();
    ~Automaton();

private:
    Node* root;
};

#endif  // SFF_AUTOMATON_H_
