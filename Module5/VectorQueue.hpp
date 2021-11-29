#ifndef VECTORQUEUE_HPP
#define VECTORQUEUE_HPP

#include <iostream>
#include <list>
#include <vector>
using namespace std;
//definitions
template <class T, int size = 100>
class VectorQueue
{
    private:
        vector<T> queue;
    public:
        VectorQueue();
        void enqueue(T &el);
        T dequeue();
        bool isFull() const;
        bool isEmpty() const;
};

//implementation
template <class T, int size>
VectorQueue<T, size>::VectorQueue()
{
    queue.reserve(size); //allocating the desired amount of memory for the intended queue size
}
template <class T, int size>
void VectorQueue<T, size>::enqueue(T &el)
{
    if (isFull())
        cout << "Queue is full\n";
    else
        queue.push_back(el); // placing a value at the back of the queue
}
template <class T, int size>
T VectorQueue<T, size>::dequeue()
{
    if (isEmpty())
    {
        throw domain_error ("Queue is empty"); // closes the program and sends the error message provided if you try to dequeue when the queue is empty
    }
    else
    {
        T el = queue.front();
        queue.erase(queue.begin()); // popping out the value at the beginning of the queue
        return el;
    }
}
template <class T, int size>
bool VectorQueue<T, size>::isFull() const
{
    return (queue.size() == size); // this code was changed since passing a struct element through to this function would cause errors, instead using queue.size to compare the current queue size to the maximum queue size
}
template <class T, int size>
bool VectorQueue<T, size>::isEmpty() const
{
    return queue.empty();
}

#endif