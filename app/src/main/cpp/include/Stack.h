#ifndef SFF_STACK_H_
#define SFF_STACK_H_

#include "LinearContainer.h"

struct StackOverflowException {};
struct StackUnderflowException {};

template <typename T>
class Stack final : public LinearContainer<T> {
public:
    Stack(size_t capacity = TABLE_SIZE);
    virtual ~Stack();

    void push(const T& item);
    void pop();
    const T& top() const;

private:
    T* m_ptr;
};

// ----------------------------------------------------------------------------
template <typename T>
Stack<T>::Stack(size_t capacity)
        : LinearContainer<T>(capacity)
        , m_ptr(nullptr) {
}

template <typename T>
Stack<T>::~Stack() {
    m_ptr = nullptr;
}

template <typename T>
void Stack<T>::push(const T& item) {
    LinearContainer<T>::reallocateIfNeed();
    ++LinearContainer<T>::m_size;
    *(++m_ptr) = item;
}

template <typename T>
void Stack<T>::pop() {
    if (LinearContainer<T>::m_size == 0) throw StackUnderflowException();
    --LinearContainer<T>::m_size;
    --m_ptr;
}

template <typename T>
const T& Stack<T>::top() const {
    if (LinearContainer<T>::m_size == 0) throw StackUnderflowException();
    return *m_ptr;
}

#endif  // SFF_STACK_H_
