#include "../headers/node.h"

template<class T>
Node<T>::Node(const T& value, int priority) :
    value{ value }, 
    priority{ priority }
{}

template<class T>
const int Node<T>::getPriority() const 
{ 
        return this->priority; 
}

template<class T>
const T& Node<T>::getValue() const
{
    return this->value;
}

//friend std::ostream& operator<<