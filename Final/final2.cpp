#include <iostream>
#include <string> // in order to have user input for string
using namespace std;

class Course
{
    private:
        int cID; // course ID
        string cName; // course name
        int cCredit; // course credit
    public:
        Course(): cID(0), cName(){}
        Course(int id, string name, int credit)
        {
            cID = id;
            cName = name;
            cCredit = credit;
        }
        int getID()
        {
            return cID;
        }
        int getCredit()
        {
            return cCredit;
        }
        string getName()
        {
            return cName;
        }
        void printCourse()
        {
            cout << "Course ID: " << cID << "  Course Name: " << cName << "  Course units:" << cCredit << endl; 
        }
};

void qsort(Course * const, int, int);
int partition(Course * const, int, int);

int main()
{
    const int N = 10;
    Course *ptr = new Course[N]; // allocating 10 course objects worth of memory for the pointer
    int id, credit;
    string name;
    for (int i = 0; i < N; i++)
    {
        cout << "Enter the course ID: ";
        cin >> id;
        cout << "Enter the course name: ";
        cin >> name;
        cout << "Enter the course units: ";
        cin >> credit;
        *(ptr + i) = Course(id, name, credit);
    }
    cout << "Before sort:\n";
    for (int i = 0; i < N; i++)
        (ptr + i)->printCourse(); // printing the courses
    qsort(ptr, 0, N-1); //qsort(0,9)
    cout << "After sort:\n";
    for (int i = 0; i < N; i++)
        (ptr + i)->printCourse();// printing the sorted courses
}

void qsort(Course * const ptr, int first, int last)
{
    int pivot_idx;
    if (first >= last)
        return;
    pivot_idx = partition(ptr, first, last);
    qsort(ptr, first, pivot_idx -1);
    qsort(ptr, pivot_idx + 1, last);
}

int partition(Course * const ptr, int first, int last)
{
    int pivot = (ptr + last)->getID();
    int i = first - 1;
    for (int j = first; j < last; j++)
    {
        if ((ptr+j)->getID() < pivot) // checking the ids against each other
        {
            ++i; //incrementing i
            swap(*(ptr + i), *(ptr+j));
        }
    }
    swap(*(ptr+i+1), *(ptr+last));
    return i + 1;
}