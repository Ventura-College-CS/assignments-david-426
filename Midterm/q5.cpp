#include <iostream>
#include <vector>
using namespace std;

class Student
{
    private:
        int sid;
        string sname;
        double scores[3];
    public:
        Student(){}
        Student(int i, string name, double *sc)
        {

        }
        int getID()
        {

        }
        string getName()
        {

        }
        double * getScores()
        {

        }
        void setID()
        {

        }
        void setName()
        {

        }
        void setScores()
        {

        }
};

template <class T, int capacity = 30>
class Stack
{
    private:
        vector<T> pool;
    public:
        Stack(){}
        void push(const T &el)
        {

        }
        t pop()
        {

        }
        T topEl()
        {

        }
        bool isEmpty()
        {

        }
        int size()
        {

        }
};