#include <cstring>
#include "utils.h"

namespace util {
    bool isValidParensSequence(const char *sequence) {
        size_t size = strlen(sequence);
        if (size == 0) return true;
        if (size % 2 != 0) return false;

        // TODO: impl
        return true;
    }
}
