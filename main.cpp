#include "headers/global.hpp"
#include "Factorial.cpp"
#include "Queue1.cpp"

using namespace std;


int main()
{
    int n1;
    n1 = 15;
    Factorial A(n1);
    A.printFactorial();
    A.printFactorialExp();
    unsigned long long A0;
    A0 = A.getFactorial();
    cout << "\n getFactorial() >> " << A0;

    Queue1 q;
    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    std::cout << "\n\nFront: " << q.Front() << std::endl;
    std::cout << "Back: " << q.Back() << std::endl;
    std::cout << "Dequeue: " << q.Dequeue() << std::endl;
    std::cout << "Dequeue: " << q.Dequeue() << std::endl;
    std::cout << "Dequeue: " << q.Dequeue() << std::endl;
    std::cout << "Dequeue: " << q.Dequeue() << std::endl;

    return 0;
}