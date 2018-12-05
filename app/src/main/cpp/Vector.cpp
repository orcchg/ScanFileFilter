#include "Vector.h"

template <typename T>
Vector<T>::Vector(size_t capacity)
    : m_capacity(capacity)
    , m_size(0)
    , m_data(new T[capacity]) {
}

template <typename T>
Vector<T>::~Vector() {
    delete [] m_data; m_data = nullptr;
}
