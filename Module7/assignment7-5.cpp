#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void qsort(int [], int, int);
int partition(int [], int, int);
void printArray(int [], int);

int main()
{
    const int N = 14;
    int num[N];
    srand(time(0));
    for (int i = 0; i < N; i++)
        num[i] = (rand() % 10) + 1;
    printArray(num, N);
    qsort(num, 0, N-1); // qsort(0, 13)
    printArray(num, N);
}

void qsort(int num[], int first, int last)
{
    int pivot_idx;
    if (first >= last)
        return;
    pivot_idx = partition(num, first, last);
    qsort(num, first, pivot_idx -1);
    qsort(num, pivot_idx + 1, last);
}

int partition(int num[], int first, int last)
{
    int pivot = num[last];
    int i = first - 1;
    for (int j = first; j < last; j++)
    {
        if (num[j] < pivot)
            swap(num[++i], num[j]);
    }
    swap(num[i + 1], num[last]);
    return i + 1;
}

void printArray(int n[], int N)
{
    for (int i = 0; i < N; i++)
        cout << n[i] << " ";
    cout << endl;
}