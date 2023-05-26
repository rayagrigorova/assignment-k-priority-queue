﻿#include <iostream>

#include "PriorityQueue.hpp"

int main()
{
    PriorityQueue<char> q(4); // 4 priorities - 0, 1, 2 и 3.

    q.push('A', 0); //adds A with lowest priority: 0
    q.push('B', 3);
    q.push('C', 2);
    q.push('D', 2);
    q.push('E', 1);

    q.print();
    std::cout << std::endl;

    try {
        q.push('F', 5); //error! No such priority!
    }
    catch (std::invalid_argument& e) {
        std::cout << e.what() << std::endl << std::endl;
    }

    q.peek(); // B

    q.pop();
    q.print();
    std::cout << std::endl;

    q.peek(); // C
    q.pop();
    q.print();
    std::cout << std::endl;

    q.peek(); // D
    q.pop();
    q.print();
    std::cout << std::endl;

    q.peek(); // E
    q.pop();
    q.print();
    std::cout << std::endl;

    q.peek(); // A
    q.pop();
    q.print();
    std::cout << std::endl;
}
