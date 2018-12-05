#include "Vector.h"

template <typename T>
Vector<T>::Vector(size_t size)
    : size(size)
    , data(new T[size]) {}

template <typename T>
Vector<T>::~Vector() {
    delete [] data;
    data = nullptr;
}
