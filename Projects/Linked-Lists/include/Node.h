#ifndef NODE_H
#define NODE_H

// Template class for NODE
template <typename T>

class NODE
{
public:
    NODE<T> *prev;
    T data;
    NODE<T> *next;

    NODE(T value)
    {
        data = value;
        next = nullptr;
        prev = nullptr; // only for doubly ll
    }
};

#endif