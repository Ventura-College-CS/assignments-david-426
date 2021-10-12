#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char mainstr[10] = "chocolate";
    char substr[10] = "col";
    int i, j, flag = 0;

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
        {
            flag = 1;
            cout << "matched at the position " << i << endl;
        }
    }
    if (!flag)
        cout << "Unable to find the substring\n";
}