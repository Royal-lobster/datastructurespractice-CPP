#include <iostream>
using namespace std;

// creating class Stack with all the methords
class Stack
{
private:
    //data members (state)
    int stack[100], n = 100, top = -1;

public:
    //constructor
    Stack(){};
    //push methord
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
    //pop methord
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
};

//driver code=====================================================
int main()
{
    int option, element;
    Stack mystack;
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
            mystack.push(element);
            break;
        }
        case 2:
        {
            mystack.pop();
            break;
        }
        case 3:
        {
            mystack.display();
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
//End driver code================================================