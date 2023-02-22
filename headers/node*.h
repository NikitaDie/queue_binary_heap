#pragma once
#include "./node.h"                    
            
template <class T>
class Node<T*>
{
private:
    T* value;
    int priority;
     
public:
    Node(const T* value, int priority);

    Node(const T& obj);

    Node(T&& obj);

    const int getPriority() const;

    Node& operator=(const Node<T*>& obj);

    Node& operator=(Node<T*>&& obj);

    const T* getValue() const;

    friend std::ostream& operator<<(std::ostream& out, const Node<T*>& obj) //find solution
    {
        out << "(v:  " << *obj.getValue() << "; p: " << obj.getPriority() << ")";
        return out;
    }

    ~Node();
};