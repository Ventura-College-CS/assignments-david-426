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
            cout << "Something went wrong\n";
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
int PostFixExp::Evaluation()
{
    const int N = 20; //maximum size of the stack
    const int offset = 48; // in order to get the correct digits when extracting them from the expression string the given offset needs to be taken into account
    Stack<int, N> stack; //creating the stack using a vector
    char input;

    int n1, n2, result;

    for (int i = 0; i < expression.size(); i++)
    {
        input = expression[i]; // taking a single character from the string
        if (isdigit(input)) // checking if the character is a digit using an inbuilt c++ function
            stack.push(int(input) - offset); // if it is a digit the char is converted to an int and the offset is subtracted to push the true value into the stack
        else if (isOperator(input))//checking if the non digit is an operator or not
        {
            n1 = stack.pop(); //taking the most recent digit and storing it into an integer variable
            n2 = stack.pop(); // taking the second most recent digit and storing it
            result = calculate(n1, n2, input); // calculating the operation given based on the operator and two topmost digits
            stack.push(result); // storing the result in the vector so that it is operated on with the next most recent digit
        }
    }
    return stack.pop(); // returning the fully calculated result
};
