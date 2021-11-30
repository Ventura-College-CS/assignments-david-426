#include <iostream>
using namespace std;

class Student
{
    private:
        int sid;
        string sname;
        double scores[3];
    public:
        Student();
        Student(int i, string name, double *sc);
        int getID();
        string getName();
        double * getScores();
        void setID();
        void setName();
        void setScores();
};