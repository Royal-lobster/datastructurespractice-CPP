#include <iostream>
#include <cmath>
#include <stack>
using namespace std;

// functions declaration
bool isOperator(char);
bool isOperand(char);
float operation(int, int, char);
float scanNum(char);
int precedence(char);
string postfix(string);
int postfix_ans(string);

// driver code-----------------
int main()
{
    string infix;
    cout << "Please enter an expression to solve: ";
    cin >> infix;
    cout << "The infix expression of the input is : " << infix << endl;
    string postfix_exp = postfix(infix);
    cout << "The postfix expression of the input is : " << postfix_exp << endl;
    cout << "The solution of the expression is : " << postfix_ans(postfix_exp) << endl;

    return 0;
}
//-----------------------------

// functions
bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return true;
    else
        return false;
}

bool isOperand(char ch)
{
    if (ch >= '0' && ch <= '9')
        return true;
    else
        return false;
}

float scanNum(char ch)
{
    int value;
    value = ch;
    return float(value - '0'); //return float from character
}

int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

float operation(int a, int b, char op)
{
    //Perform operation
    if (op == '+')
        return b + a;
    else if (op == '-')
        return b - a;
    else if (op == '*')
        return b * a;
    else if (op == '/')
        return b / a;
    else if (op == '^')
        return pow(b, a); //find b^a
    else
        return 0; //return negative infinity
}

string postfix(string infix)
{
    stack<char> s;
    string postfix;
    for (int i = 0; i < infix.length(); i++)
    {
        // if the infix[i] is a number then do this
        if (isOperand(infix[i]))
        {
            postfix = postfix + infix[i];
        }
        // if the infix[i] is a opening bracket then do this
        else if (infix[i] == '(')
        {
            s.push(infix[i]);
        }
        // if the infix[i] is a closing bracket then do this
        else if (infix[i] == ')')
        {
            while ((s.top() != '(') && (!s.empty()))
            {
                char temp = s.top();
                postfix = postfix + temp;
                s.pop();
            }
            if (s.top() == '(')
            {
                s.pop();
            }
        }
        else if (isOperator(infix[i]))
        {
            if (s.empty() || (precedence(infix[i]) > precedence(s.top())) || ((precedence(infix[i]) == precedence(s.top())) && (infix[i] == '^')))
            {
                s.push(infix[i]);
            }
            else
            {
                while ((!s.empty()) && (precedence(infix[i]) <= precedence(s.top())))
                {
                    postfix = postfix + s.top();
                    s.pop();
                }
                s.push(infix[i]);
            }
        }
    }
    while (!s.empty())
    {
        postfix = postfix + s.top();
        s.pop();
    }
    return postfix;
}

int postfix_ans(string postfix)
{
    int a, b;
    stack<float> s;
    for (int i = 0; i < postfix.length(); i++)
    {
        if (isOperator(postfix[i]))
        {
            a = s.top();
            s.pop();
            b = s.top();
            s.pop();
            s.push(operation(a, b, postfix[i]));
        }
        else
        {
            s.push(scanNum(postfix[i]));
        }
    }

    return s.top();
}
