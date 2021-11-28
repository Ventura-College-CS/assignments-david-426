#ifndef POSTFIX_H
#define POSTFIX_H

#include "stack.h" // general stack file given to us in class
#include <string>
using namespace std;

class PostFixExp
{
    private:
        string expression;
        int isOperator(char);
        int calculate(int, int, char); 
    public:
        PostFixExp();
        PostFixExp(string);
        void setExpression(string);
        void printExpression() const;
        int Evaluation();
};

#endif