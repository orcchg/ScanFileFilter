#include <cstring>
#include "CLogReader.h"

CLogReader::CLogReader() {
}

CLogReader::~CLogReader() {
}

bool CLogReader::SetFilter(const char* filter) {
    size_t size = strlen(filter);
    return false;
}

bool CLogReader::AddSourceBlock(const char* block, const size_t block_size) {
    return false;
}
