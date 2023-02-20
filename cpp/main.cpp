#include <iostream>
#include "./templates.cpp"
//#include "../headers/node.h"
//#include "../headers/queue.h"

/*template <class T>
class Node
{
private:
    T value;
    int priority;

public:
    Node(const T& value, int priority) : 
        value{ value }, 
        priority{ priority }
    {}

    const int getPriority() const 
    { 
        return this->priority; 
    }

    const T& getValue() const 
    { 
        return this->value; 
    }

    friend std::ostream& operator<<(std::ostream& out, const Node<T>& obj)
    {
        out << "(v:  " << obj.getValue() << "; p: " << obj.getPriority() << ")";
        return out;
    }
    
};

template <class T>
class Queue
{
private:
    Node<T>** arr;
    int count;
    int capacity{ 8 };

    const int getParentIndex(int index) const
    {
        return (index - 1) / 2;
    }

    const int getParentPriority(int index) const
    {
        return this->arr[getParentIndex(index)]->getPriority();
    }

    const int getLeftChildIndex(int index) const
    {
        int tmp_index{ 2 * index + 1 };
        if(tmp_index > this->count)
            return -3;// ?

        return tmp_index;
    }

    const int getRightChildIndex(int index) const
    {
        int tmp_index{ 2 * index + 2 };
        if(tmp_index > this->count)
            return -3;// ?

        return tmp_index;
    }

    const int getLeftChildPriority(int index) const 
    {
        return this->arr[getLeftChildIndex(index)]->getPriority();
    }

    const int getRightChildPriority(int index) const
    {
        return this->arr[getRightChildIndex(index)]->getPriority();
    }

    const int getLargerChildIndex(int index) const
    {
        if(getRightChildPriority(index) > getLeftChildPriority(index))
            return getRightChildIndex(index);
        
        return getLeftChildIndex(index);
    }

    const int getLargerChildPriority(int index) const
    {
        return this->arr[getLargerChildIndex(index)]->getPriority();
    }

    void swap(int index1, int index2)
    {
        Node<T>* temp = this->arr[index1];
        this->arr[index1] = this->arr[index2];
        this->arr[index2] = temp;
    }

public:
    Queue() :
        arr{ new Node<T>*[8]},
        count{ 0 }
    {}

    void push(Node<T>* value)
    {
        if (count == 0)
        {
            arr[count++] = value;
            return;
        }

        arr[count++] = value;
    
        int i{ count - 1 };
        int parentPriority{ getParentPriority(i) };

        while((i > 0) && (arr[i]->getPriority() > parentPriority))
        {
            
            swap(i, getParentIndex(i));

            i = getParentIndex(i);
            parentPriority = getParentPriority(i);
        }
    }

    Node<T> pop()
    {
        Node<T> temp = *arr[0];

        arr[0] = arr[count - 1];
        int i{ 0 };
        this->count--;

        while (i < this->count - 1) // ?
        {
            if (arr[i]->getPriority() < this->getLargerChildPriority(i))
            {
                swap(i, this->getLargerChildIndex(i));
                i = getLargerChildPriority(i);
            }
            else
                return temp;
        }

        return temp;
    }

    void show()
    {
        for (int i{ 0 }; i < this->count; ++i)
        {
            std::cout << *arr[i] << " ";
            
        }
    }


    //const T& front

    //back

    int size() const
    {
        return this->count;
    }

    //empty()     

};*/

enum Priority
{
    LOW = 0,
    NORMAL = 1,
    HIGH = 2,
};


int main() {

    Queue<int, 8> q;
    q.push(new Node<int>{10, Priority::LOW});
    q.show();
    std::cout << std::endl;

    q.push(new Node<int>{20, Priority::HIGH});
    q.show();
    std::cout << std::endl;
    
    q.push(new Node<int>{30, Priority::NORMAL});
    q.show();
    std::cout << std::endl;

    q.push(new Node<int>{40, Priority::LOW});
    q.show();
    std::cout << std::endl;

    q.push(new Node<int>{50, Priority::NORMAL});
    q.show();
    std::cout << std::endl;

    q.push(new Node<int>{60, Priority::HIGH});
    q.show();
    std::cout << std::endl;
    std::cout << std::endl;
    while( q.size() > 0 )
    {
        std::cout << q.pop() << std::endl;
    }

    return 0;
};