#ifndef SFF_LINEAR_CONTAINER_H_
#define SFF_LINEAR_CONTAINER_H_

#include <cstddef>
#include "constants.h"

template <typename T>
class LinearContainer {
public:
    LinearContainer(size_t capacity = TABLE_SIZE);
    LinearContainer(const LinearContainer<T>& obj);
    virtual ~LinearContainer();

    inline size_t capacity() const { return m_capacity; }
    inline bool empty() const { return m_size == 0; }
    inline size_t size() const { return m_size; }

protected:
    size_t m_capacity;
    size_t m_size;
    T* m_data;

    void reallocateIfNeed();
};

// ----------------------------------------------------------------------------
template <typename T>
LinearContainer<T>::LinearContainer(size_t capacity)
        : m_capacity(capacity)
        , m_size(0)
        , m_data(new T[capacity]) {
}

template <typename T>
LinearContainer<T>::LinearContainer(const LinearContainer<T>& obj)
        : m_capacity(obj.m_capacity)
        , m_size(obj.m_size)
        , m_data(new T[m_capacity]) {

    for (size_t i = 0; i < m_size; ++i) {
        m_data[i] = obj.m_data[i];
    }
}

template <typename T>
LinearContainer<T>::~LinearContainer() {
    delete [] m_data; m_data = nullptr;
}

template <typename T>
void LinearContainer<T>::reallocateIfNeed() {
    if (m_size == m_capacity) {
        m_capacity *= 2;
        T* data = new T[m_capacity];
        for (size_t i = 0; i < m_size; ++i) {
            data[i] = m_data[i];
        }
        delete [] m_data; m_data = data;
    }
}

#endif  // SFF_LINEAR_CONTAINER_H_
