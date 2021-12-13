#include <iostream>
#include <string>
#include "PostFix.h"
using namespace std; //PostFixExp:: is included for specification on the class functions being referred to

int PostFixExp::isOperator(char sym) //sym = symbol
{
    switch(sym)
    {
        case '*': //as long as it is an operator it returns 1 for true, otherwise it returns 0 for false
        case '/':
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
};
int PostFixExp::calculate(int n1, int n2, char sym) // num1, num2, and symbol
{
    int result;
    switch (sym)
    {
        case '*':
            result = n1 * n2;
            break; // break is required otherwise the other cases will be called as well
        case '/':
            result = n1/n2;
            break;
        case '+':
            result = n1 + n2;
            break;
        case '-':
            result = n1 - n2;
            break;
        default:
            cout << "An error occurred\n";
            exit(0);
    }
    return result;
};
PostFixExp::PostFixExp(){};
PostFixExp::PostFixExp(string exp) // exp is short for expression
{
    expression = exp; // setting the expression as the input string
};
void PostFixExp::setExpression(string exp)
{
    expression = exp;
};
void PostFixExp::printExpression() const
{
    for (int i = 0; i < expression.size(); i++)
    {
        cout << expression[i] << "\t"; // printing the expression as is since there was no specification about doing otherwise
    }
    cout << endl;
};

