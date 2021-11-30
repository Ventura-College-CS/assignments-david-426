#include <iostream>
#include <vector>
using namespace std;

const int MAX_SCORES = 3;

class Student
{
    private:
        int sid;
        string sname;
        double scores[MAX_SCORES];
    public:
        Student(){}
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