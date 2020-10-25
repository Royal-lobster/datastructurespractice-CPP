#include <iostream>
#define MAX 10
using namespace std;

// global functions
int queue[MAX];
int front = -1;
int rear = -1;

// function declaration
bool isempty();
bool isfull();
void enqueue(int);
void dequeue();
int peek();
void printqueue();

// driver function
int main()
{
    int option;
    int element;

    cout << endl
         << "Options : " << endl
         << "1) Add item to the Queue" << endl
         << "2) Remove element from the Queue" << endl
         << "3) Peak the first element from the Queue" << endl
         << "4) Print the queue" << endl
         << "5) exit" << endl;

    do
    {
        cout << endl
             << "--------------------------------------------" << endl
             << "Please select an Option (1 / 2 / 3 / 4 / 5) : ";
        cin >> option;
        cout << "--------------------------------------------" << endl;

        switch (option)
        {
        case 1:
            cout << "Please enter an element to add to Queue : ";
            cin >> element;
            enqueue(element);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            if (isempty())
            {
                cout << "ERROR : The queue is empty. So cannot be peaked" << endl;
            }
            else
            {
                cout << "The first element is : " << peek() << endl;
            }
            break;

        case 4:
            printqueue();

        case 5:
            cout << sizeof(queue) << endl;

        default:
            break;
        }

    } while (option != 6);

    return 0;
}

// functions
void enqueue(int el)
{
    if (isfull())
        cout << "ERROR: The queue is full. Please remove elements to add new element" << endl;
    else
    {
        rear++;
        queue[rear] = el;
        cout << "Element added sucessfully" << endl;
    }
}
void dequeue()
{
    if (isempty())
        cout << "ERROR: The queue is empty. Please add elements to continue." << endl;
    else
    {
        front++;
        int removedElement = queue[front];
        cout << "Element " << removedElement << " removed sucessfully" << endl;
    }
}
bool isempty()
{
    if (front >= rear)
        return true;
    else
        return false;
}
bool isfull()
{
    if (rear == MAX - 1)
        return true;
    else
        return false;
}
int peek()
{
    return queue[front + 1];
}
void printqueue()
{
    if (isempty())
        cout << "ERROR : The queue is empty. Cannot print it" << endl;
    else
    {
        for (int i = front; i <= rear; i++)
        {
            cout << queue[i + 1] << " <-- ";
        }
        cout << endl
             << "Front: " << front << ", Rear: " << rear << endl;
    }
}