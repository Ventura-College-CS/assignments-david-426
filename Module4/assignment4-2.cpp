#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int N = 64;
void makeArray(int [], int N);
int linearSearch(int [], int N, int target);
int binarySearch(int [], int N, int target);
void sortArray(int [], int N);

int main()
{
    int array[N];
    int target, linearSum = 0, binarySum = 0; //linearSum and binarySum are going to be used to add together all of the comparisons made per search function call
    srand(time(0)); // in order to randomize the numbers by time
    makeArray(array, N);
    for (int i = 0; i < 100; i++)
    {
        target = array[rand()%64]; //rand()%64 gives values between 0 and 63 
        linearSum += linearSearch(array, N, target);
    }
    sortArray(array, N);
    for (int i = 0; i < 100; i++) // I decided to use two for loops in order to keep the two evaluations fair since the advantage of a linear search over a binary search
    {                             // is that you don't need to sort the array beforehand. Also this lets me call the sortArray() function outside of the loop
        target = array[rand()%64];
        binarySum += binarySearch(array, N, target);
    }
    cout << "The average amount of comparisons made through linear search: " << (double)(linearSum)/100 << endl; // I made the average a double in order to be more accurate
    cout << "The average amount of comparisons made through binary search: " << (double)(binarySum)/100 << endl;
}

void makeArray(int array[], int N)
{
    srand(time(0));
    for (int i = 0; i < N; i++)
    {
        array[i] = (rand() % 100) + 1; // in order to have the numbers be from 1 to 100 rather than 0 to 99.
    }
}

int linearSearch(int array[], int N, int target)
{
    int compNum = 0;
    for (int i = 0; i < N; i++) // going through the array one step at a time in order.
    {
        compNum++;
        if (target == array[i])
        {
            break;
        }
    }
    return compNum;
}

int binarySearch(int array[], int N, int target)
{
    int compNum, first, last, mid;
    compNum = first = 0;
    last = N-1;
    while (first <= last) // binary search method as shown in class.
    {
        mid = (first + last)/2;
        compNum++;
        if (target == array[mid])
            break;
        else if (target < array[mid])
            last = mid - 1;
        else
            first = mid + 1;
    }
    return compNum;
}

void sortArray(int array[], int N)
{
    int temp;
    for (int i = 0; i < N; i++) // sorting the array through bubble sort
    {
        for (int j = 0; j < N; j++)
        {
            if (array[i] < array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}