#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int binarySearch(int [], int, int, int); //you must change the function parameters for recursion to work for a binary search
void makeArray(int [], int);
void sortArray(int [], int);

int main()
{
    const int N = 64;
    int array[N];
    int target, indexFound, first = 0, last = N - 1;
    srand(time(0));
    makeArray(array, N);
    sortArray(array, N);
    cout << "The sorted array is: \n";
    for (int v: array) // printing out the sorted array
    {
        cout << v << " ";
    }
    cout << endl;
    target = array[rand()%64]; // choosing a random number within the array
    indexFound = binarySearch(array, first, last, target);
    cout << "The index of " << target << " was found to be: " << indexFound << " using binary search.";
}

void makeArray(int array[], int N)
{
    srand(time(0));
    for (int i = 0; i < N; i++)
    {
        array[i] = (rand() % 100) + 1; // in order to have the numbers be from 1 to 100 rather than 0 to 99.
    }
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

int binarySearch(int array[], int first, int last, int target)
{
    int mid = (first + last)/2; //by implementing the recursive version of binary search you no longer need a while loop, however you must also create the first and last values in the main function to call it
    if (target == array[mid])
    {
        cout << "The target was found\n";
        return mid;
    }
    else if (target < array[mid])
    {
        cout << "The target was less than the current mid index\n";
        return binarySearch(array, first, mid - 1, target);
    }
    else
    {
        cout << "The target was greater than the current mid index\n";
        return binarySearch(array, mid + 1, last, target);
    }
}
/* The pros of using the recursive version of binary search are that there is no longer any reason to include a loop within the binary search function which theoretically could reduce
the time complexity of the program as well as making the program easier to understand since simple if else statements are generally going to be the main method of determining when to 
call the next function sequence or not.
The cons of using the recursive version of binary search are that more memory has to be allocated for the program using this method since the function is called multiple times 
and each function call will not finish until the final function call returns the desired default condition value.
*/