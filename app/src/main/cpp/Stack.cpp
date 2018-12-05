#include "Stack.h"

template <typename T>
Stack<T>::Stack(size_t capacity)
    : m_capacity(capacity)
    , m_size(0)
    , m_data(new T[capacity])
    , m_ptr(nullptr) {
}

template <typename T>
Stack<T>::~Stack() {
    delete [] m_data; m_data = nullptr;
    m_ptr = nullptr;
}

template <typename T>
void Stack<T>::push(const T& item) {
    if (m_size >= m_capacity) throw StackOverflowException();
    ++m_size;
    *(++m_ptr) = item;
}

template <typename T>
void Stack<T>::pop() {
    if (m_size == 0) throw StackUnderflowException();
    --m_size;
    --m_ptr;
}

template <typename T>
const T& Stack<T>::top() const {
    if (m_size == 0) throw StackUnderflowException();
    return *m_ptr;
}