#include "../headers/queue.h"

template <class T, int step>
const int Queue<T, step>::getParentIndex(int index) const
{
    return (index - 1) / 2;
}

template <class T, int step>
const int Queue<T, step>::getParentPriority(int index) const
{
    return this->arr[getParentIndex(index)]->getPriority();
}

template <class T, int step>
const int Queue<T, step>::getLeftChildIndex(int index) const
{
        return 2 * index + 1;
}

template <class T, int step>
const int Queue<T, step>::getRightChildIndex(int index) const
{
    return 2 * index + 2;
}

template <class T, int step>
const int Queue<T, step>::getLeftChildPriority(int index) const 
{
    return this->arr[getLeftChildIndex(index)]->getPriority();
}

template <class T, int step>
const int Queue<T, step>::getRightChildPriority(int index) const 
{
    return this->arr[getRightChildIndex(index)]->getPriority();
}

template <class T, int step>
const int Queue<T, step>::getLargerChildIndex(int index) const
{
    if (getRightChildPriority(index) > getLeftChildPriority(index))
        return getRightChildIndex(index);
        
    return getLeftChildIndex(index);
}

template <class T, int step>
const int Queue<T, step>::getLargerChildPriority(int index) const
{
    return this->arr[getLargerChildIndex(index)]->getPriority();
}

template <class T, int step>
void Queue<T, step>::swap(int index1, int index2)
{
    Node<T>* temp = this->arr[index1];
    this->arr[index1] = this->arr[index2];
    this->arr[index2] = temp;
}

template <class T, int step>
void Queue<T, step>::clearMemory()
{
    if (this->arr == nullptr)
        return;
        
    for (int i{}; i < this->count; ++i)
    {
        delete this->arr[i];
    }

    delete[] this->arr;
    this->arr = nullptr;
    this->count = 0;
    this->capacity = 0;

}

template <class T, int step>
Queue<T, step>::Queue() :
    arr{ new Node<T>*[step]},
    count{ 0 },
    capacity{ 0 }
{}

template <class T, int step>
Queue<T, step>::Queue(const Queue& obj) :
    arr{ new Node<T>*[obj.count]},
    count{ obj.count },
    capacity{ obj.capacity }
{
    for(int i{}; i < obj.count; ++i)
    {
        this->arr[i] = obj.arr[i];
    }
}

template <class T, int step>
Queue<T, step>& Queue<T, step>::operator=(const Queue& obj)
{
    if(this == &obj)
        return *this;

    this->clearMemory();

    this->arr = new Node<T>*[obj.count];
    this->count = obj.count;
    this->capacity = obj.count;

    for(int i{}; i < obj.count; ++i)
    {
        this->arr[i] = obj.arr[i];
    }

    return *this;
}

template <class T, int step>
Queue<T, step>::Queue(Queue&& obj) :
    arr{ obj.arr },
    count{ obj.count },
    capacity{ obj.count }
{
    obj.arr = nullptr;
}


template <class T, int step>
Queue<T, step>& Queue<T, step>::operator=(Queue&& obj)
{
    if(this == &obj)
        return *this;

    this->clearMemory();

    this->arr = obj.arr;
    this->count = obj.count;
    this->capacity = obj.capacity;

    obj.arr = nullptr;

    return *this;
}

template <class T, int step>
void Queue<T, step>::push(Node<T>* value)
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

template <class T, int step>
Node<T> Queue<T, step>::pop()
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

//front
//back

template <class T, int step>
int Queue<T, step>::size() const
{
    return this->count;
}

template <class T, int step>
bool Queue<T, step>::empty() const
{
    if (count == 0)
        return true;

    return false;
}

template <class T, int step>
void Queue<T, step>::clear()
{
    clearMemory();
}

template <class T, int step>
void Queue<T, step>::show() const
{
    for (int i{ 0 }; i < this->count; ++i)
    {
        std::cout << *arr[i] << " ";   
    }
}

template <class T, int step>
Queue<T, step>::~Queue()
{
    clearMemory();
}