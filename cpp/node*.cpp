#include "../headers/node*.h"

template<class T>
Node<T*>::Node(const T* value, int priority) :
    value{ new T{ *value } }, 
    priority{ priority }
{}

template<class T>
Node<T*>::Node(const T& obj) :
    value{ new T{ *obj.value } },
    priority{ obj.priority }
{}

template<class T>
Node<T*>::Node(T&& obj) :
    value{ obj.value },
    priority{ obj.priority }
{
    obj.value = nullptr;
}

template<class T>
Node<T*>& Node<T*>::operator=(const Node<T*>& obj) 
{
    if (this == &obj)
    {
        return *this;
    }

    delete this->value;

    this->value = new T{ *obj.value };
    this->priority = obj.priority;

    return *this;
}

template<class T>
Node<T*>& Node<T*>::operator=(Node<T*>&& obj)
{
    if (this == &obj)
    {
        return *this;
    }

    delete this->value;

    this->value = obj.value;
    this->priority = obj.priority;

    obj.value = nullptr;
}

template<class T>
const int Node<T*>::getPriority() const 
{ 
        return this->priority; 
}

template<class T>
const T* Node<T*>::getValue() const
{
    return this->value;
}


template<class T>
Node<T*>::~Node()
{
    if (this->value != nullptr)
        delete this->value;

    this->priority = 0;
}
//friend std::ostream& operator<<