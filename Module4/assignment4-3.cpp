#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void makeArray(int [], int);
void printArray(int [], int);
void selectionSort(int [], int);

int main()
{
    const int N = 10;
    int array[N];

    makeArray(array, N);
    printArray(array, N);
    selectionSort(array, N);
    printArray(array, N);
}

void makeArray(int array[], int N)
{
    srand(time(0));
    for (int i = 0; i < N; i++)
        array[i] = rand() % 100;
}

void printArray(int array[], int N)
{
    for (int i = 0; i < N; i++)
        cout << array[i] << " ";
    cout << endl;
}
void selectionSort(int array[], int N)
{
    int min, minIndex, temp;
    for (int i = 0; i < N-1; i++) // set to go up to N - 1 to ensure that i + 1 doesn't go outside the bounds of the array
    {
        min = array[i];
        for (int j = i + 1; j < N; j++)
        {
            if (min > array[j])
            {
                min = array[j];
                minIndex = j;
            }
        }
        if (i != minIndex)
        {
            temp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = temp;
        }
    }
}