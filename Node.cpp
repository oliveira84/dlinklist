#include "Node.h"

template <class T>
Node<T>::Node(T key)

{
    next = nullptr;
    prev = nullptr;
    this->key = key;
}

template <class T>
Node<T>::~Node()
{
}
