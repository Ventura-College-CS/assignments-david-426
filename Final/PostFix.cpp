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
