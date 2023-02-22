#include <iostream>
#include "./templates.cpp"
//#include "../headers/node.h"
//#include "../headers/queue.h"

enum Priority
{
    LOW = 0,
    NORMAL = 1,
    HIGH = 2,
};

int main() {

    /*Queue<int, 8> q;
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
    }*/

    Queue<int*, 8> w;


    w.push(new Node<int*>{new int{10}, Priority::LOW});
    w.show();

    return 0;
};