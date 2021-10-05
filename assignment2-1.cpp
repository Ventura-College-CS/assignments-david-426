#include <iostream>
using namespace std;

int main()
{
    const int N = 10;
    double arr[N] = {5.0, 3.2, 5.6, 9.5, 7.3, 4.2, 10.2, 14.6, 6.4, 2.5};
    double *ptr = arr;

    cout << ptr << endl; //This shows the memory address of the first value in the array

    for (int i = 0; i < N; i++)
    {
        cout << *(ptr+i) << "\t"; //This calls the pointer's dereferenced value at the value i which starts from 0 and goes up to 9 for all the array values
    }                             //(goes up by 4 bytes for each value to new address in the array)
    cout << endl;
}