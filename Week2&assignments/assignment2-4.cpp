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

    ptr = makeStudents(N); // copying the pointer returned by the makeStudents function
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

    ifs.open("students.txt"); // opening the students.txt file in order to read from the file
    if (ifs.fail())
    {
        cerr << "Error unable to open file\n";
        exit(0); // exits the program if unable to open file
    }

    for (int i = 0; i < N; i++)
    {
        ifs >> (ptr+i) ->sid >> (ptr+i)->sname; //reading the students data from the file line by line (in this case the id and student name)
        for (int j = 0; j < NUM_SCORES; j++)
        {
            ifs >> (ptr+i)->scores[j]; // reads each score in the line individually (for easier future changes in number of scores)
            if (ifs.fail())
            {
                cerr << "File Read Error";
                exit(0);
            }
        }
    }
    ifs.close(); // closes the file associated with the ifs variable
    return ptr; //Returning the pointer to the main program
}

void printStudents(Students * const ptr, int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << (ptr+i)->sid << "\t"; // printing the student id
        cout << (ptr+i)->sname << "\t"; // printing the student name
        for (int j = 0; j < NUM_SCORES; j++)
            cout << (ptr+i)-> scores[j] << "\t"; // printing the student scores individually (to allow for easier changes if the number of scores change)
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
    for (int i = 0; i < N; i++) //I use the bubble sort method in order to sort the student's from lowest to highest score sum by using the sum pointer's list of values
    {
        for (int j = i+1; j < N; j++)
        {
            if (*(sumptr+i) > *(sumptr+j)) //Since the order of the score sums is in the same order as that of the students they correspond to I can use the double pointer to sort both into the proper order
            {
                Students temp = *(ptr+i); // creating a temporary student variable in order to swap the values at each dynamically allocated memory address within the pointer
                *(ptr+i) = *(ptr+j); // puting the value in the memory address associated with j into the address associated with i
                *(ptr+j) = temp;  // puting the value from the memory address associated with i that was saved into the temporary student struct variable into the memory address associated with j
                sum = *(sumptr+i); //reusing sum as a temporary variable to sort the sumptr values to keep both pointer memory allocations in the same order throughout the process
                *(sumptr+i) = *(sumptr+j);
                *(sumptr+j) = sum;
            }
        }
    }
    delete sumptr; //releasing allocated memory associated with the sum pointer
}