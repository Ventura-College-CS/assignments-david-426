#include <iostream>
using namespace std;

void printArray(double * const n, int N);

int main()
{
    const int N = 10;
    double arr[N] = {5.0, 3.2, 5.6, 9.5, 7.3, 4.2, 10.2, 14.6, 6.4, 2.5};
    printArray(arr, N);
}

void printArray(double * const n, int N)
{
    for (int i = 0; i < N; i++)
        cout << *(n + i) << "\t";
    cout << endl;
}