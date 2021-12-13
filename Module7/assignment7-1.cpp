#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int factorial(int);
int summation(int);
int evenNums(int [], int, int);

int main()
{
    const int N = 10;
    int array[N], n, start = 0;
    srand(time(0));

    n = (rand() % 10) + 1; // in order to avoid n = 0 as a possibility
    cout << n << "! = " << factorial(n) << endl;
    n = (rand() % 100) + 1;
    cout << "The summation of all numbers leading up to " << n << " is " << summation(n) << endl; 

    for (int i = 0; i < N; i++)
        array[i] = (rand() % 100) + 1; // not including 0 in the range so you get numbers from 1 to 100
    cout << "The array is:\n";
    for (int v : array)
        cout << v << " ";
    cout << endl;

    cout << "The number of even numbers in the given array is " << evenNums(array, start, N) << endl;
}

int factorial(int n)
{
    if (n == 1) // if n = 1 then the recursive function returns 1
        return 1;
    else // otherwise return the current n multiplied with another of the same function call with n-1 as the parameter. i.e. if n = 5 the program will return 5 * factorial(4) and so on
        return n*factorial(n-1); 
}

int summation(int n)
{
    if (n == 1) // ends the recursion when n = 1 to avoid an infinite recursion loop
        return 1;
    else
        return n + summation(n - 1); // otherwise return the current n added to another of the same function call with n-1 as the parameter. i.e. if n = 5 the program will return 5 + factorial(4) and so on
}

int evenNums(int array[], int n, int size)
{
    if (n == size - 1 && array[n] % 2 == 0) // checking if we are at the end of the array and whether or not the number is even, if so return 1
        return 1;
    else if (n == size - 1) // you no longer need to check if it is even and as such you will return 0 since we are still at the end of the array
        return 0;
    else if (array[n] % 2 == 0) // checks if the current number in the array is even
        return 1 + evenNums(array, n+1, size); // returns 1 + another function call if it is to add to the counter. i.e if array[1] = 4 then 1 is added to the recursive summation of 1s and 0s
    else
        return 0 + evenNums(array, n+1, size); // adds 0 to the recursive counter since the number is not even
}