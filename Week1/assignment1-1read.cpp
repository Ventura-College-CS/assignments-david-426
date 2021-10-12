#include <iostream>
#include <fstream>
using namespace std;

struct Student
{
    int id;
    char sname[20];
    double score[2];
    double sum;
    double avg;
};

void printStudent(Student s);
void findStudent(Student s[], int idNum);

int main()
{
    ifstream ifs;
    Student s[10];
    int idNum;

    ifs.open("students.bin");

    if (ifs.fail())
    {
        cout << "Could not open the file\n";
        exit(0);
    }

    for (int i = 0; i < 10; i++)
    {
        ifs.read((char *)&s, sizeof(s));
        cout << "ID: " << s[i].id << "\t";
        cout << "Name: " << s[i].sname << "\t";
        cout << "Average: " << s[i].avg << "\n";
    }

    //search for student information
    cout << "Enter ID: ";
    cin >> idNum;
    findStudent(s, idNum);
    ifs.close();
}


void findStudent(Student s[], int idNum)
{
    int flag = 0;
    for (int i = 0; i < 10; i++)
    {
        if (idNum == s[i].id)
        {
            flag = 1;
            printStudent(s[i]);
            break;
        }
    }
    if (!flag)
        cout << "This ID number is invalid\n";
}

void printStudent(Student s)
{
    cout << "ID: " << s.id << "\t";
    cout << "Name: " << s.sname << "\t";
    cout << "Score 1: " << s.score[0] << "\t";  
    cout << "Score 2: "<< s.score[1] << "\t";
    cout << "Sum: " << s.sum << "\t";
    cout << "Average: "<< s.avg << endl;    
}
