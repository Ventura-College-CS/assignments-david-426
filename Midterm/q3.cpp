#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int numbers[] = {10, 20, 15, 30, 40, 50}; //changed the values on line 1
	deque<int> dq(numbers + 1, numbers + 4); // showing a variation of the declaration on line 2
	cout << " Dequeued : " << dq.front() << endl;
	dq.pop_front();
	cout << " Dequeued : " << dq.front() << endl;
	dq.pop_front();
	cout << " Dequeued from rear: " << dq.back() << endl;
	dq.pop_back();
	cout << " Dequeued from rear: " << dq.back() << endl;
	dq.pop_back();
}