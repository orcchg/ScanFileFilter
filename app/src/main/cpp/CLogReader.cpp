#include <cstring>
#include "CLogReader.h"
#include "utils.h"

CLogReader::CLogReader() {
}

CLogReader::~CLogReader() {
}

bool CLogReader::SetFilter(const char* filter) {
    if (!util::isValidParensSequence(filter)) {
        return false;
    }

    size_t size = strlen(filter);

    // TODO:
    return false;
}

bool CLogReader::AddSourceBlock(const char* block, const size_t block_size) {
    return false;
}
