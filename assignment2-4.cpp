#include <iostream>
#include <fstream>
using namespace std;

const int MAX_LEN = 20;
const int NUM_SCORES = 3;

struct Students
{
    int sid;
    char sname[MAX_LEN];
    double scores[NUM_SCORES];
};

Students *makeStudents(int);
void printStudents(Students * const, int);
void sortStudents(Students * const, int);

int main()
{
    const int N = 10;
    Students *ptr;

    ptr = makeStudents(N);
    printStudents(ptr, N);
    cout << "\nStudents sorted by score sum\n";
    sortStudents(ptr, N);
    printStudents(ptr, N);
    delete ptr; // releasing allocated memory
}

Students *makeStudents(int N)
{
    ifstream ifs;
    Students *ptr = new Students[N];

    ifs.open("students.txt");
    if (ifs.fail())
    {
        cerr << "Error unable to open file\n";
        exit(0);
    }

    for (int i = 0; i < N; i++)
    {
        ifs >> (ptr+i) ->sid >> (ptr+i)->sname;
        for (int j = 0; j < NUM_SCORES; j++)
        {
            ifs >> (ptr+i)->scores[j];
            if (ifs.fail())
            {
                cerr << "File Read Error";
                exit(0);
            }
        }
    }
    ifs.close();
    return ptr;
}

void printStudents(Students * const ptr, int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << (ptr+i)->sid << "\t";
        cout << (ptr+i)->sname << "\t";
        for (int j = 0; j < NUM_SCORES; j++)
            cout << (ptr+i)-> scores[j] << "\t";
        cout << endl;
    }
}

void sortStudents(Students * const ptr, int N)
{
    double *sumptr = new double[N]; //sum pointer = sumptr
    double sum;
    for (int i = 0; i < N; i++)
    {
        sum = 0;
        for (int j = 0; j < NUM_SCORES; j++)
            sum += (ptr+i)->scores[j];
        *(sumptr+i) = sum; //Fills in the pointer memory allocation with the sums of each student's scores in the order they appear
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = i+1; j < N; j++)
        {
            if (*(sumptr+i) > *(sumptr+j)) //Since the order of the score sums is the same as that of the students I can use the double pointer to sort both
            {
                Students temp = *(ptr+i);
                *(ptr+i) = *(ptr+j);
                *(ptr+j) = temp;  
                sum = *(sumptr+i); //reusing sum as a temporary variable to sort the sumptr values to keep both pointer memory allocations in line with each other
                *(sumptr+i) = *(sumptr+j);
                *(sumptr+j) = sum;
            }
        }
    }
    delete sumptr;
}