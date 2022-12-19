#ifndef QUEUE1_HPP
#define QUEUE1_HPP

#pragma once

#include "global.hpp"

constexpr int kQueueSize = 10;

class Queue1
{
public:
    Queue1();
    bool IsEmpty() const;
    bool IsFull() const;
    void Enqueue(int value);
    int Dequeue();
    int Front() const;
    int Back() const;

private:
    std::array<int, kQueueSize> data_;
    int front_;
    int back_;
};
#endif // QUEUE1_HPP