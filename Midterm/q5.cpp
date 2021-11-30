#include <iostream>
#include <vector>
#include <string>
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

template <class T, int capacity = 30>
class Stack
{
    private:
        vector<T> pool;
    public:
        Stack()
        {
            pool.reserve(capacity);
        }
        void push(const T &el)
        {
            pool.push_back(el);
        }
        T pop()
        {
            T el = pool.back();
            pool.pop_back();
            return el;
        }
        T &topEl()
        {
            return pool.back();
        }
        bool isEmpty()
        {
            return pool.empty();
        }
        int size()
        {
            return pool.size();
        }
};

int main()
{
    int id;
    string name;
    double scores[MAX_SCORES];
    Stack<Student, 5> students;
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
        students.push(Student(id, name, scores)); // generating a student object and passing it into the stack
    }

    cout << "Stack size: " << students.size() << endl;

    while (!students.isEmpty())
    {
        Student spop = students.topEl();
        students.pop();
        spop.printStudent();
    }
}