#include <iostream>
#include <list>
#include <queue>
using namespace std;

int main()
{
    list <int> list1(5, 100); // changing values changes how many of which value is stored
    queue<int, list<int>> lq(list1);
    cout << "Dequeued : " << lq.front() << endl;
    lq.pop();
    cout << "Dequeued : " << lq.front() << endl;
    lq.pop();
}