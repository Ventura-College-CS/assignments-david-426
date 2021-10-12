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

int main()
{
    ifstream ifs;
    ofstream ofs;

    ifs.open("students.txt");
    ofs.open("students.bin");

    if (ifs.fail())
    {
        cerr << "Error unable to open file";
        exit(0);
    }

    const int N = 10;
    Students *ptr = new Students[N];

    for (int i = 0; i < N; i++)
    {
        ifs >> (ptr+i)->sid >> (ptr+i)->sname;
        for (int j = 0; j < NUM_SCORES; j++)
        {
            ifs >> (ptr+i)->score[j];
            if (ifs.fail())
            {
                cerr << "File Read Error";
                exit(0);
            }
        }
        ofs.write((char *)(ptr+i), sizeof(Students));
    }
    ifs.close();
    ofs.close();
}