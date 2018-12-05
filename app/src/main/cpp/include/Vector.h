#ifndef SFF_VECTOR_H_
#define SFF_VECTOR_H_

#include "constants.h"

// TODO: impl reallocate
template <typename T>
class Vector final {
public:
    Vector(size_t capacity = TABLE_SIZE);
    virtual ~Vector();

    inline size_t capacity() const { return m_capacity; }
    inline size_t size() const { return m_size; }

private:
    size_t m_capacity;
    size_t m_size;
    T* m_data;
};

#endif  // SFF_VECTOR_H_
