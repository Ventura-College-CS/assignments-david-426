#include <iostream>
#include <string>
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
            cout << "Course ID: " << cID << "\tCourse Name: " << cName << "\t Course units:" << cCredit << endl; 
        }
};

Course binarySearch(Course [], int, int, int);
void sortCourses(Course * const, int);

int main()
{
    const int N = 10;
    Course *ptr = new Course[N];
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
}

Course binarySearch(Course * const c, int target, int first, int last)
{
    int mid = (first + last) / 2;
    if (target == (c+mid)->getID())
        return *(c+mid);
    else if (target < (c+mid)->getID())
        return binarySearch(c, target, first, last - 1);
    else
        return binarySearch(c, target, first + 1, last);
}

void sortCourses(Course * const ptr, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if ((ptr + j)->getID() > (ptr + i)->getID())
            {
                Course temp = *(ptr+i);
                *(ptr+i) = *(ptr+j); // puting the value in the memory address associated with j into the address associated with i
                *(ptr+j) = temp;  // puting the value from the memory address associated with i that was saved into the temporary student struct variable into the memory address associated with j
            }
        }
    }
}