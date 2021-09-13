#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char mainstr[10] = "chocolate";
    char substr[10] = "col";
    int pos, i, j;

    cout << sizeof(mainstr) << endl;
    cout << sizeof(substr) << endl;

    cout << strlen(substr) << endl;
    cout << strlen(mainstr) << endl;

    for (i = 0; i < strlen(mainstr) - strlen(substr) + 1; i++)
    {
        for (j = 0; j < strlen(substr); j++)
        {
            if (substr[j] != mainstr[i+j])
                break;
        }
        if (j == strlen(substr))
            cout << "matched at the position " << i << endl;
    }
}