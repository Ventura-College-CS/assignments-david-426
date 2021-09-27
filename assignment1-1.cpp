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

int main()
{
    ifstream ifs;
    ofstream ofs;

    Student s[10];

    ifs.open("students.txt");
    ofs.open("students.bin");

    if (ifs.fail())
    {
        cout << "Could not open the file\n";
        exit(0);
    }

    for (int i = 0; i < 10; i++)
    {
        ifs >> s[i].id;
        ifs >> s[i].sname;
        ifs >> s[i].score[0];
        ifs >> s[i].score[1];
        s[i].sum = s[i].score[0] + s[i].score[1];
        s[i].avg = s[i].sum/2.0;

        cout << "ID: " << s[i].id << "\t";
        cout << "Name: " << s[i].sname << "\t";
        cout << "Score 1: " << s[i].score[0] << "\t";
        cout << "Score 2: " << s[i].score[1] << "\t";
        cout << "Sum: " << s[i].sum << "\t";
        cout << "Average: " << s[i].avg << endl;

        ofs.write((char *)&s, sizeof(s));
    }
    ifs.close();
    ofs.close();
}