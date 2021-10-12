#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void fillupArray(int *, int);
void printArray(int * const, int);

int main()
{
    const int N = 10;
    int *ptr = new int[N];

    fillupArray(ptr, N);
    printArray(ptr, N);
    delete ptr;
}

void fillupArray(int * ptr, int N)
{
    srand(time(0));
    for (int i = 0; i < N; i++)
    {
        *(ptr+i) = rand() % 100;
    }
}

void printArray(int * const ptr, int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << *(ptr+i) << "\t";
    }
    cout << endl;
}