#include <iostream>
#include <string>
#include <queue>
using namespace std;

const int MAX_SCORES = 3;

class Student
{
    private:
        int sid;
        string sname;
        double scores[MAX_SCORES];
    public:
        Student(): sid(0), sname(){}
        Student(int i, string name, double *sc)
        {
            sid = i;
            sname = name;
            for (int i = 0; i < MAX_SCORES; i++)
                scores[i] = *(sc + i);
        }
        int getID()
        {
            return sid;
        }
        string getName()
        {
            return sname;
        }
        double * getScores()
        {
            double *sc = new double[3];
            for (int i = 0; i < MAX_SCORES; i++)
                *(sc + i) = scores[i];
            return sc;
        }
        void setID(int id)
        {
            sid = id;
        }
        void setName(string name)
        {
            sname = name;
        }
        void setScores(double *sc)
        {
            for (int i = 0; i < MAX_SCORES; i++)
                scores[i] = *(sc + i);
        }
        void printStudent()
        {
            cout << "ID: " << sid << "\t" << "Name: " << sname << "\t";
            for (int i = 0; i < MAX_SCORES; i++)
                cout << scores[i] << "\t";
            cout << endl;
        }
};

class StudentCompare
{
    public:
       double operator()(Student &lhs, Student &rhs)
        {
            double lhssum = 0.0; 
            double rhssum = 0.0;
            double *sc = lhs.getScores();
            for (int i = 0; i < MAX_SCORES; i++)
                lhssum += *(sc + i);
            sc = rhs.getScores();
            for (int i = 0; i < MAX_SCORES; i++)
                rhssum += *(sc + i);
            return lhssum < rhssum;   
        }
};

int main()
{
    
}