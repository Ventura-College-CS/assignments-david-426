#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

double *makeNumbers(int N);
void sortNumbers(double *, int N);
void printNumbers(double *, int N);
void deleteNumbers(double *);

int main()
{
    const int N = 10;
    double *ptr;

    ptr = makeNumbers(N);
    printNumbers(ptr, N);
    sortNumbers(ptr, N);
    printNumbers(ptr, N);
    deleteNumbers(ptr);
}

double *makeNumbers(int N)
{
    double *ptr;
    ptr = new double[N];

    srand(time(0));
    for (int i = 0; i < N; i++)
    {
        *(ptr+i) = (double)(rand()%1000) / 100; //creating a random double value from 0 to 100 and dividing by 100 to get random values from 0 to 10 with 2 values after the decimal
    }
    return ptr;
}

void sortNumbers(double *ptr, int N)
{
    double temp = *ptr;
    for (int i = 0; i < N; i++)
    {
        for (int j = i+1; j < N; j++)
        {
            if (*(ptr+i) > *(ptr+j))
            {
                temp = *(ptr+i);
                *(ptr+i) = *(ptr+j);
                *(ptr+j) = temp;
            }
        }
    }
}

void printNumbers(double *ptr, int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << *(ptr+i) << "\t";
    }
    cout << endl;
}

void deleteNumbers(double *ptr)
{
    delete ptr;
}