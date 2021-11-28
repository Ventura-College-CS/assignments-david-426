#ifndef STACK
#define STACK

#include <vector>
#include <iostream>
using namespace std;

template <class T, int capacity = 30>
class Stack
{
    private:
        vector<T> pool;
    public:
        Stack()
        {
            pool.reserve(capacity);
        }
        void clear()
        {
            pool.clear();
        }
        bool isEmpty() const
        {
            return pool.empty();
        }
        T &topEl()
        {
            return pool.back;
        }
        T pop()
        {
            T el = pool.back();
            pool.pop_back();
            return el;
        }
        void push(const T &el)
        {
            pool.push_back(el);
        }
        int size()
        {
            return pool.size();
        }
        void print() const
        {
            for (int v: pool)
                cout << v << "\t";
            cout << endl; 
        }
};

#endif