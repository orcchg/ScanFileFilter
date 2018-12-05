#ifndef SFF_C_LOG_READER_H_
#define SFF_C_LOG_READER_H_

#include <cstddef>

class CLogReader {
public:
    CLogReader();
    virtual ~CLogReader();

    /**
     * Set up filter for input strings.
     *
     * @return TRUE for success, FALSE in case of any error.
     */
    bool SetFilter(const char* filter);

    /**
     * Add text block.
     */
    bool AddSourceBlock(const char* block, const size_t block_size);
};

#endif  // SFF_C_LOG_READER_H_
