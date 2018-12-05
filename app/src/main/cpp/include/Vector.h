#ifndef SFF_VECTOR_H_
#define SFF_VECTOR_H_

#include "LinearContainer.h"

template <typename T>
class Vector final : public LinearContainer<T> {
public:
    Vector(size_t capacity = TABLE_SIZE);
    virtual ~Vector();
};

// ----------------------------------------------------------------------------
template <typename T>
Vector<T>::Vector(size_t capacity)
        : LinearContainer<T>(capacity) {
}

template <typename T>
Vector<T>::~Vector() {
}

#endif  // SFF_VECTOR_H_
