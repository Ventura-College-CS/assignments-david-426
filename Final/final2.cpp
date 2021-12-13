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
        if ((ptr+j)->getID() < pivot)
        {
            ++i;
            swap(*(ptr + i), *(ptr+j));
        }
    }
    swap(*(ptr+i+1), *(ptr+last));
    return i + 1;
}