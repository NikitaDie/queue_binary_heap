#pragma once
#include <iostream>

template <class T>
class Node
{
private:
    T value;
    int priority;

public:
    Node(const T& value, int priority);

    const int getPriority() const;

    const T& getValue() const;

    friend std::ostream& operator<<(std::ostream& out, const Node<T>& obj) //find solution
    {
        out << "(v:  " << obj.getValue() << "; p: " << obj.getPriority() << ")";
        return out;
    }
};