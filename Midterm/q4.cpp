#include <iostream>
#include <list>
#include <queue>
using namespace std;

int main()
{
    list <int> list1(5, 100);
    queue<int, list<int>> lq(list1);
    cout << "Dequeued : " << lq.front() << endl;
    lq.pop();
    cout << "Dequeued : " << lq.front() << endl;
    lq.pop();
}