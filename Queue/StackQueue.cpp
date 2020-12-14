#include <iostream>
#define MAX 50
using namespace std;

// global variables
int top1 = -1;
int top2 = -1;
int stack1[MAX];
int stack2[MAX];

// function declaration
void push(int stackNum, int element);
void pop(int stackNum);

// driver function
int main()
{
}

// functions
void push(int stackNum, int element)
{
    if (stackNum == 1)
    {
        top1++;
        stack1[top1] = element;
    }
    else if (stackNum == 2)
    {
        top2++;
        stack2[top2] = element;
    }
    else
        cout << "only 1 and 2 are allowed for stackNum";
}
void pop(int stackNum)
{
    if (stackNum == 1)
    {
        top1--;
    }
    else if (stackNum = 2)
    {
        top2--;
    }
    else
        cout << "only 1 and 2 are allowed for stackNum";
}