#include <iostream>
#include <fstream>
using namespace std;

const int LEN_NAME = 20;
const int NUM_SCORES = 3;
struct Students
{
    int sid;
    char sname[LEN_NAME];
    double score[NUM_SCORES];
};

void printStudents(Students, int);
void greaterThan85(Students * const, int);

int main()
{
    const int N = 10;
    ifstream ifs;
    Students *ptr = new Students[N];

    ifs.open("students.bin");
    if (ifs.fail())
    {
        cerr << "Error Unable To Open File";
        exit(0);
    }

    for (int i = 0; i < N; i++)
    {
        ifs.read((char *)(ptr+i), sizeof(Students));
    }

    greaterThan85(ptr, N);
    delete ptr;
    ifs.close();
}

void printStudents(Students s, int N)
{
    cout << s.sid << "\t";
    cout << s.sname << "\t";
    for (int i = 0; i < NUM_SCORES; i++)
    {
        cout << s.score[i] << "\t";
    }
    cout << endl;
}

void greaterThan85(Students * const ptr, int N)
{
    double sum = 0;
    double avg = 0;

    for (int i = 0; i < N; i++)
    {
        sum = 0;
        for (int j = 0; j < NUM_SCORES; j++)
            sum += (ptr+i)->score[j];
        avg = sum/NUM_SCORES;

        if (avg > 85)
            printStudents(*(ptr+i), N);
    }
}