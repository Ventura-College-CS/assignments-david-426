#include <iostream>
#include <fstream>
#include <vector>
#include <string> //including the string library in order to resolve errors associated with using the string class
using namespace std;

void initVectors(vector<int> & , vector<string> &, int);
void printVectors(vector<int> , vector<string> , int);
void sortVectors(vector<int> &, vector<string> &, int);

int main()
{
    const int N = 10;
    vector<int> IDs(N);
    vector<string> names(N);

    initVectors(IDs, names, N);
    printVectors(IDs, names, N);
    sortVectors(IDs, names, N);
    printVectors(IDs, names, N);
}

void initVectors(vector<int> &IDs, vector<string> &names, int N)
{
    ifstream ifs;
    ifs.open("vectordata.txt"); // opening the file with the IDs and names

    if (ifs.fail()) // exits if unable to open file
    {
        cerr << "Error: Unable to Open File\n";
        exit(0);
    }
    for (int i = 0; i < N; i++) // used to fill in the IDs and names vectors
    {
        ifs >> IDs[i] >> names[i];
        if (ifs.fail()) // exits if there is a file read error
        {
            cerr << "File Read Error\n";
            exit(0);
        }
    }
    ifs.close(); //closing the file
}

void printVectors(vector<int> IDs, vector<string> names, int N)
{
    for (int i = 0; i < N; i++) // printing the vectors side by side for each set
        cout << IDs[i] << "\t" << names[i] << endl;
    cout << endl;
}

void sortVectors(vector<int> &IDs, vector<string> &names, int N)
{
    int pos, tempInt; //used for determining which character of the string differs between the two names
    string temp;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            pos = 0;
            while(names[i].at(pos) == names[j].at(pos) && names[i].compare(names[j]) != 0) // this is done to find at what position the names differ. .at() is used to compare characters in the array
                pos++;                                                                      // names.compare() is used to ensure that the while loop ends even if the two names are the same
            if (names[i].at(pos) < names[j].at(pos)) //Once the differing characters between the two names is found they are compared and switched in order to obtain an order from A to Z for the names
            {
                temp = names[i];
                names[i] = names[j];
                names[j] = temp;
                tempInt = IDs[i]; // switching the names and IDs at the same time in order to ensure that each ID is set to the matching name that they were assigned to
                IDs[i] = IDs[j];
                IDs[j] = tempInt;
            }
        }
    }
}