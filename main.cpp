#include <iostream>

#include "PriorityQueue.hpp"

int main()
{
    PriorityQueue<char> q(4); // 4 priorities - 0, 1, 2 и 3.

    q.push('A', 0); 
    q.push('B', 3);
    q.push('C', 2);
    q.push('D', 2);
    q.push('E', 1);
    q.push('F', 1);
    q.push('G', 3);
    q.push('H', 2);
    q.push('I', 0);

    // Order in the queue (descending): B, G, C, D, H, E, F, A, I

    q.print();
    std::cout << std::endl;

    try {
        q.push('F', 5); // Error! No such priority!
    }
    catch (std::invalid_argument& e) {
        std::cout << e.what() << std::endl << std::endl;
    }

    std::cout << "Peek: " << q.peek() << std::endl << std::endl; // B
    q.pop();
    q.print(); // G, C, D, H, E, F, A, I
    std::cout << std::endl;

    std::cout << "Peek: " << q.peek() << std::endl << std::endl; // G
    q.pop();
    q.print();// C, D, H, E, F, A, I
    std::cout << std::endl;

    std::cout << "Peek: " << q.peek() << std::endl << std::endl; // C
    q.pop();
    q.print(); // D, H, E, F, A, I
    std::cout << std::endl;

    std::cout << "Peek: " << q.peek() << std::endl << std::endl; // D
    q.pop();
    q.print(); // H, E, F, A, I
    std::cout << std::endl;

    std::cout << "Peek: " << q.peek() << std::endl << std::endl; // H
    q.pop();
    q.print(); // E, F, A, I
    std::cout << std::endl;
}

