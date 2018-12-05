#ifndef SFF_VECTOR_H_
#define SFF_VECTOR_H_

#include <cstddef>

template <typename T>
class Vector {
public:
    Vector(size_t size = 32);
    virtual ~Vector();

private:
    size_t size;
    T* data;
};

#endif  // SFF_VECTOR_H_
