#include <iostream>
#define MAX 5
using namespace std;
class Queue
{
private:
    int queue[MAX];
    int front = -1;
    int rear = -1;

public:
    // constructor
    Queue() {}

    // methrods
    void enqueue(int el)
    {
        if (isfull())
            cout << "ERROR: Queue Overflow" << endl;
        else
        {
            rear++;
            queue[rear] = el;
            cout << "Element added sucessfully" << endl;
        }
    }
    void dequeue()
    {
        if ((front == (MAX - 1)) && (rear == (MAX - 1)))
        {
            cout << "MESSAGE: The queue is dead due to array overflow" << endl;
        }
        else if (isempty())
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
        {
            cout << endl
                 << "Front: " << front << ", Rear: " << rear << ", MAX-1:" << MAX - 1 << endl;
            cout << "ERROR : The queue is empty. Cannot print it" << endl;
        }
        else
        {
            for (int i = front; i < rear; i++)
            {
                cout << queue[i + 1] << " <-- ";
            }
            cout << endl
                 << "Front: " << front << ", Rear: " << rear << ", MAX-1:" << MAX - 1 << endl;
        }
    }
};

//driver code=====================================================
int main()
{
    int element, option;
    Queue myqueue;
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
            myqueue.enqueue(element);
            break;

        case 2:
            myqueue.dequeue();
            break;

        case 3:
            if (myqueue.isempty())
            {
                cout << "ERROR : The queue is empty. So cannot be peaked" << endl;
            }
            else
            {
                cout << "The first element is : " << myqueue.peek() << endl;
            }
            break;

        case 4:
            myqueue.printqueue();

        default:
            break;
        }

    } while (option != 6);

    return 0;
}
//End driver code================================================