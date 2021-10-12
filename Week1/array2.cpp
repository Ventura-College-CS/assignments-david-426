#include <iostream>
using namespace std;

void swap(int a, int b, int (&numbers)[10])
{
    int temp = numbers[a];
    numbers[a] = numbers[b];
    numbers[b] = temp;
}

int main()
{
    const int N = 10;
    int nums[N] = {5, 7, 2, 4, 6, 7, 10, 1, 3, 9};
    int temp;
    
    for (int v: nums)
        cout << v << "\t";
    cout << endl;
    
    for (int i = 0; i < (N/2); i++)
    {
        swap(i, (N-i-1), nums);
    }

    for (int v: nums)
        cout << v << "\t";
    
}