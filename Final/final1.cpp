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

int main()
{

}