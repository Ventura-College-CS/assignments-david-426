#include <iostream>
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

void makeStudents(Students [], int);
void printStudents(Students [], int);
void bubbleSortbyID(Students [], int);
int binarySearch(Students [], int, int);


int main()
{
    const int N = 10;
    Students s[N];
    int target, foundidx;
    makeStudents(s, N);
    bubbleSortbyID(s, N);
    cout << "Students sorted by ID: \n";
    printStudents(s, N);

    cout << "Enter the student's ID you wish to retrieve: ";
    cin  >> target;
    foundidx = binarySearch(s, target, N);
    if (foundidx == -1)
        cout << "This student ID: " << target << "could not be found in the database of students\n";
    else
    {
        cout << "Student's name: " << s[foundidx].sname << endl << "Scores: ";
        for (int i = 0; i < MAX_SCORES; i++)
            cout << s[foundidx].scores[i] << "\t";
        cout << endl;
    }  

}

void makeStudents(Students s[], int N)
{
    ifstream ifs;
    ifs.open("students.txt"); // quick note I changed the student ids since there were three students who had the id 10007777
    if (ifs.fail())
    {
        cerr << "File Open Error\n";
        exit(0);
    }

    for (int i = 0; i < N; i++)
    {
        ifs >> s[i].sid >> s[i].sname;
        for (int j = 0; j < MAX_SCORES; j++)
        {
            ifs >> s[i].scores[j];
            if (ifs.fail())
            {
                cerr << "File Read Error\n";
                exit(0);
            }
        }
    }
}

void printStudents(Students s[], int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << s[i].sid << "\t" << s[i].sname << "\t";
        for (int j = 0; j < MAX_SCORES; j++)
            cout << s[i].scores[j] << "\t";
        cout << endl;
    }
}

void bubbleSortbyID(Students s[], int N)
{
    Students temp;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (s[i].sid < s[j].sid)
            {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}

int binarySearch(Students s[], int target, int N)
{
    int first, last, mid, pos;
    first = 0;
    pos = -1;
    last = N-1;
    while (first <= last)
    {
        mid = (first + last)/2;
        if (s[mid].sid == target)
        {
            pos = mid;
            break;
        }
        else if (s[mid].sid < target)
            first = mid + 1;
        else
            last  = mid - 1;
    }
    return pos;
}