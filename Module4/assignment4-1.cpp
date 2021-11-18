#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    const int N = 10;
    int first = 0, last = N-1, mid, target;
    int intArray[N];
    srand(time(0));

    for (int i = 0; i < N; i++) // creating an array of 10 random integers between 0 and 100
        intArray[i] = rand() % 100;
    target = intArray[rand()%N];
    for (int i = 0; i < N; i++) // sorting the array so I can use binary search method
    {
        for (int j = 0; j < N; j++)
        {
            if (intArray[i] < intArray[j])
            {
                int temp = intArray[i];
                intArray[i] = intArray[j];
                intArray[j] = temp;
            }
        }
    }
    for (int v: intArray)
        cout << v << " ";
    cout << endl;
    cout << "The targeted number is : " << target << endl;
    while (first <= last)
    {
        mid = (first + last)/2;
        if (intArray[mid] == target)
        {
            cout << "Target number found at index: " << mid << endl;
            break;
        }
        else if (intArray[mid] < target)
            first = mid + 1;
        else
            last = mid - 1;
    }
}