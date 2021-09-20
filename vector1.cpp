#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printVector(vector<int> vec);
void addToVector(vector<int> &vec, int num);
void deleteFromVector(vector<int> &vec, int num);

int main()
{
    vector<int> numbers = {10, 13, 5, 7, 25};
    int new_number;
    printVector(numbers);
    sort(numbers.begin(), numbers.end());
    printVector(numbers);
    
    cout << "Enter your number to insert: ";
    cin >> new_number;
    addToVector(numbers, new_number);
    printVector(numbers);

    cout << "Enter your number to delete: ";
    cin >> new_number;
    deleteFromVector(numbers, new_number);
    printVector(numbers);
}

void printVector(vector<int> vec)
{
    vector<int>::iterator it;
    for (it = vec.begin(); it < vec.end(); it++)
    {
        cout << *it << "\t";
    }
    cout << endl;
}

void addToVector(vector<int> &vec, int num)
{
    vector<int>::iterator it;
    for (it = vec.begin(); it < vec.end(); it++)
    {
        if (*it > num)
            break;
    }
    vec.insert(it, num);
}

void deleteFromVector(vector<int> &vec, int num)
{
    vector<int>::iterator it;
    for (it = vec.begin(); it <vec.end(); it++)
    {
        if (*it > num)
        {
            vec.erase(it-1);
            break;
        }
    }
    if (it == vec.end())
        cout << "Desired value not found\n";
}