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
    int id;
    string name;
    double scores[MAX_SCORES];
    Student pop_student;
    priority_queue<Student, vector<Student>, StudentCompare> pq;
    for (int i = 0; i < 5; i++) // done 5 times
    {
        cout << "Enter the ID: ";
        cin >> id;
        cout << "Enter name: ";
        cin >> name;
        for (int j = 0; j < MAX_SCORES; j++)
        {
            cout << "Enter Score " << j + 1 << ": ";
            cin >> scores[j];
        }
        pq.push(Student(id, name, scores)); // pushing the students into the priority queue
    }
 
    while (!pq.empty())
    {
        pop_student = pq.top();
        pop_student.printStudent();
        pq.pop();
    }
}