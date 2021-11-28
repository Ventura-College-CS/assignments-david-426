#include "PostFix.h"
#include <iostream>
using namespace std;

int main()
{
    PostFixExp e1;

    e1.setExpression("243*+5+");
    e1.printExpression();
    cout << "The result of this expression is " << e1.Evaluation() << endl;
}