#ifndef SFF_STACK_H_
#define SFF_STACK_H_

#include "constants.h"

struct StackOverflowException {};
struct StackUnderflowException {};

// TODO: impl reallocate
template <typename T>
class Stack final {
public:
    Stack(size_t capacity = TABLE_SIZE);
    virtual ~Stack();

    inline size_t capacity() const { return m_capacity; }
    inline size_t size() const { return m_size; }

    void push(const T& item);
    void pop();
    const T& top() const;

private:
    size_t m_capacity;
    size_t m_size;
    T* m_data;
    T* m_ptr;
};

#endif  // SFF_STACK_H_
