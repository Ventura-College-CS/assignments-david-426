#include "VectorQueue.hpp"
#include <iostream>
#include <list>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

const int MAX_LEN = 20;
const int MAX_SCORES = 3;

struct Students
{
    int sid;
    char sname[MAX_LEN];
    double scores[MAX_SCORES];
};

void makeStudents(VectorQueue<Students, 10> &, int); // function used to show how enqueue can be used in order to fill the queue from a separate text file, also to show what happens when the queue is full
void printStudents(VectorQueue<Students, 10> &, int);// function used to show how dequeue can be used in order to pull out elements of the queue and print them, also to show how the program exits when the queue is empty

int main()
{
    const int N = 10;
    srand(time(0));
    VectorQueue<int, N> arrayQueue;
    for (int i = 0; i < N; i++)
    {
        int n = rand() % 100; //creating random integer values
        arrayQueue.enqueue(n); // 1. enqueueing the integer values
    }
    for (int i = 0; i < N; i++)
    {
        int popnum = arrayQueue.dequeue(); // 2. dequeueing the integer values into the popnum int variable
        cout << popnum << endl; //printing the popped numbers
    }
    VectorQueue<Students, N> studentQueue; // 3. Creating the variable studentQueue rather than arrayQueue to avoid issues with having two similar variables with the same name
    makeStudents(studentQueue, N);
    printStudents(studentQueue, N);
}

void makeStudents(VectorQueue<Students, 10> &v, int N)
{
    ifstream ifs;
    Students s;
    ifs.open("students.txt");
    if (ifs.fail())
    {
        cerr << "Open File Error\n";
        exit(0);
    }
    for (int i = 0; i < N + 1; i++) // 5. adding one too many students to enqueue to show what happens
    {
        ifs >> s.sid >> s.sname;
        for (int j = 0; j < MAX_SCORES; j++)
        {
            ifs >> s.scores[j];
            if (ifs.fail())
            {
                cerr << "File Read Error\n";
                exit(0);
            }
        }
        v.enqueue(s); // 4. placing the current student information into the queue
    }
}

void printStudents(VectorQueue<Students, 10> &v, int N)
{
    for (int i = 0; i < N + 1; i++) // 6. adding one too many students to dequeue in order to show that the program exits when you try to dequeue one too many times
    {
        Students s = v.dequeue(); // 4. popping out the Student at the end of the queue through the calling of dequeue()
        cout << s.sid << "\t" << s.sname << "\t";
        for (int j = 0; j < MAX_SCORES; j++)
            cout << s.scores[j] << "\t";
        cout << endl;
    }
}