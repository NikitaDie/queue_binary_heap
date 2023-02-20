#pragma once
#include "./node.h"

template <class T, int step = 8>
class Queue
{
private:
    Node<T>** arr;
    int count;
    int capacity;

    const int getParentIndex(int index) const;

    const int getParentPriority(int index) const;

    const int getLeftChildIndex(int index) const;

    const int getRightChildIndex(int index) const;

    const int getLeftChildPriority(int index) const;

    const int getRightChildPriority(int index) const;

    const int getLargerChildIndex(int index) const;

    const int getLargerChildPriority(int index) const;

    void swap(int index1, int index2);

    void clearMemory();

public:
    Queue();

    Queue(const Queue& obj);

    Queue& operator=(const Queue& obj);

    Queue(Queue&& obj);

    Queue& operator=(Queue&& obj);

    void push(Node<T>* value);

    Node<T> pop();

    const T& front() const;

    const T& back() const;

    int size() const;

    bool empty() const;

    void clear();

    void show() const;

    ~Queue();
};