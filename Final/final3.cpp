#include <iostream>
#include <string>
#include "PostFix.h"
using namespace std;

int main()
{
    string exp;
    cout << "Please Enter your postfix expression";
    cin >> exp;
    PostFixExp e1;
    e1.setExpression(exp);
    
}