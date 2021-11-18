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
void bubbleSortbyName(Students [], int);
void bubbleSortbyScores(Students [], int);

int main()
{
    const int N = 10;
    Students s[N];
    makeStudents(s, N);
    printStudents(s, N);

    bubbleSortbyID(s, N);
    cout << "Sorted by ID: \n";
    printStudents(s, N); 

    bubbleSortbyName(s, N);
    cout << "Sorted by Name: \n";
    printStudents(s, N);

    bubbleSortbyScores(s, N);
    cout << "Sorted by Score sum: \n";
    printStudents(s, N); 
}

void makeStudents(Students s[], int N)
{
    ifstream ifs;
    ifs.open("students.txt");
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

void bubbleSortbyName(Students s[],int N)
{
    int letPos; // letPos = letter position
    Students temp;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            letPos = 0;
            while (s[i].sname[letPos] == s[j].sname[letPos] && s[i].sname != s[j].sname)
                letPos++;
            if (s[i].sname[letPos] < s[j].sname[letPos])
            {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}

void bubbleSortbyScores(Students s[], int N)
{
    double sum1, sum2;
    Students temp;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            sum1 = sum2 = 0;
            for(int k = 0; k < MAX_SCORES; k++)
            {
                sum1 += s[i].scores[k];
                sum2 += s[j].scores[k];
            }
            if (sum1 > sum2)
            {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}

