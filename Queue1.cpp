#include "headers/Queue1.hpp"

Queue1::Queue1() : front_(0), back_(0) {}

bool Queue1::IsEmpty() const { return front_ == back_; }

bool Queue1::IsFull() const { return (back_ + 1) % kQueueSize == front_; }

void Queue1::Enqueue(int value)
{
    if (IsFull())
    {
        std::cout << "Queue is full!" << std::endl;
        return;
    }
    data_[back_] = value;
    back_ = (back_ + 1) % kQueueSize;
}

int Queue1::Dequeue()
{
    if (IsEmpty())
    {
        std::cout << "Queue1 is empty!" << std::endl;
        return -1;
    }
    int value = data_[front_];
    front_ = (front_ + 1) % kQueueSize;
    return value;
}

int Queue1::Front() const
{
    if (IsEmpty())
    {
        std::cout << "Queue is empty!" << std::endl;
        return -1;
    }
    return data_[front_];
}

int Queue1::Back() const
{
    if (IsEmpty())
    {
        std::cout << "Queue is empty!" << std::endl;
        return -1;
    }
    return data_[(back_ - 1 + kQueueSize) % kQueueSize];
}