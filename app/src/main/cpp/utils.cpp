#include <cstring>
#include "Stack.h"
#include "utils.h"

namespace util {

    bool isValidParensSequence(const char* sequence) {
        size_t size = strlen(sequence);
        if (size == 0) return true;
        if (size % 2 != 0 || sequence[0] == PAREN_CLOSE) return false;

        Stack<char> stack;
        if (sequence[0] == PAREN_OPEN) {
            stack.push(PAREN_OPEN);
        }

        /**
         * Need to start from index '1' in order to check previous character in sequence.
         */
        for (size_t i = 1; i < size; ++i) {
            if (sequence[i - 1] != SLASH) {  // omit escaped '\(' and '\)' as being not control chars
                switch (sequence[i]) {
                    case PAREN_OPEN:
                        stack.push(PAREN_OPEN);
                        break;
                    case PAREN_CLOSE:
                        stack.pop();
                        break;
                    default:
                        break;
                }
            }
        }

        return stack.empty();
    }

}
