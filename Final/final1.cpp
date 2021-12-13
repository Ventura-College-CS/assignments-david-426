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
};

Course binarySearch(Course * const, int, int, int);
void sortCourses(Course * const, int);

int main()
{

}

Course binarySearch(Course c[], int target, int first, int last)
{
    int mid = (first + last) / 2;
    if (target == c[mid].getID())
        return c[mid];
    else if (target < c[mid].getID())
        return binarySearch(c, target, first, last - 1);
    else
        return binarySearch(c, target, first + 1, last);
}