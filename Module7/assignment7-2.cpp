#include <iostream>
using namespace std;

int fibo(int);

int main()
{
    int n = 5;
    cout << "The 5th sequence number in the fibbonacci series: " << fibo(n) << endl;
}

int fibo(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    else
        return fibo(n-1) + fibo(n-2);
}