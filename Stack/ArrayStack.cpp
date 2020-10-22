#include <iostream>
using namespace std;

//global variables
int stack[100], n = 100, top = -1;

//function declaration
void push(int element);
void pop();
void display();

//main function
int main()
{
    int option, element;
    cout << "Options :" << endl
         << "1) Push in stack" << endl
         << "2) Pop from stack"
         << endl
         << "3) Display stack"
         << endl
         << "4) Exit"
         << endl;
    do
    {
        cout << "Enter Options: ";
        cin >> option;
        switch (option)
        {
        case 1:
        {
            cout << "Enter value to be pushed: ";
            cin >> element;
            push(element);
            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            display();
            break;
        }
        case 4:
        {
            cout << "Exit" << endl;
            break;
        }
        default:
        {
            cout << "Invalid Choice" << endl;
        }
        }

    } while (option != 4);
    return 0;
}

// functions
void push(int element)
{
    if (top >= n - 1)
        cout << "Stack Overflow" << endl;
    else
    {
        top++;
        stack[top] = element;
    }
}
void pop()
{
    if (top <= -1)
        cout << "Stack Underflow" << endl;
    else
    {
        cout << "The popped element is " << stack[top] << endl;
        top--;
    }
}
void display()
{
    if (top >= 0)
    {
        cout << "Stack elements are:";
        for (int i = top; i >= 0; i--)
            cout << stack[i] << " ";
        cout << endl;
    }
    else
        cout << "Stack is empty";
}