#include <iostream>
using namespace std;

// create a class for Node
class Node
{
public:
    // state
    int key;
    int data;
    Node *next;

    // methords
    Node()
    {
        key = 0;
        data = 0;
        next = NULL;
    }
    Node(int k, int d)
    {
        key = k;
        data = d;
    }
};

// create a class for singly linked list
class singlylinkedlist
{
public:
    // state
    Node *head;
    int currentKey;

    // methods

    // constructor
    singlylinkedlist()
    {
        head = NULL;
        int currentKey = 0;
    }

    // 1. Print the list
    void printList()
    {
        if (head == NULL)
        {
            cout << "The List is Empty." << endl;
        }
        else
        {
            Node *ptr = head;
            cout << "here is the List: " << endl;
            while (ptr != NULL)
            {
                cout << "[" << ptr->key << "," << ptr->data << "] --> ";
                ptr = ptr->next;
            }
            cout << endl;
        }
    }

    // 2. methord to return the address of the node if it exits in the list
    Node *nodeAddressInList(int k)
    {
        Node *ptr = head;
        while (ptr != NULL)
        {
            if (ptr->key == k)
            {
                return ptr;
            }
            ptr = ptr->next;
        }
        return NULL;
    }

    // 3. Append Node
    void appendNode(Node *node)
    {
        // check weather a node is present or not
        if (head != NULL)
        {
            node->key = ++currentKey;
        }
        if (nodeAddressInList(node->key) != NULL)
        {
            cout << "The node already exits in the list" << endl;
            return;
        }
        else
        {
            if (head == NULL)
            {
                head = node;
            }
            else
            {
                Node *ptr = head;
                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = node;
            }
            cout << "The node sucessfully appended to the list" << endl;
            return;
        }
    }

    //4. Prepend Node
    void prependNode(Node *node)
    {
        if (head != NULL)
        {
            node->key = ++currentKey;
        }
        //check if the node is present already in the list
        if (nodeAddressInList(node->key) != NULL)
        {
            cout << "The node already exits in the list" << endl;
            return;
        }
        else
        {
            node->next = head;
            head = node;
            cout << "The node successfully prepended" << endl;
            return;
        }
    }
    // 5. Insert a Node after a particular node in the list
    void insertNodeAfter(int k, Node *node)
    {
        if (head != NULL)
        {
            node->key = ++currentKey;
        }
        Node *ptr = nodeAddressInList(k);
        if (ptr == NULL)
        {
            cout << "No node exists with key value: " << k << endl;
            return;
        }
        else
        {
            //check if the node is present already in the list
            if (nodeAddressInList(node->key) != NULL)
            {
                cout << "The node already exits in the list" << endl;
                return;
            }
            else
            {
                node->next = ptr->next;
                ptr->next = node;
                cout << "Node successfully inserted" << endl;
            }
        }
    }
    // 6. Delete node by unique key
    void deleteNodeByKey(int k)
    {
        Node *prvNode = nodeAddressInList(k - 1);
        Node *node = nodeAddressInList(k);

        if (node == NULL)
        {
            cout << "There is no node with key " << k << " to delete" << endl;
            return;
        }
        if (prvNode != NULL)
        {
            prvNode->next = node->next;
        }
        else
        {
            head = node->next;
        }
        cout << "Node [" << node->key << "," << node->data << "] sucessfully deleted" << endl;
        node = NULL;
    }
    // 7. update node by key
    void updateNodeByKey(int k, int d)
    {
        Node *ptr = nodeAddressInList(k);
        if (ptr == NULL)
        {
            cout << "There is no node with key " << k << " to update" << endl;
            return;
        }
        else
        {
            cout << "Node [" << ptr->key << "," << ptr->data << "] ";
            ptr->data = d;
            cout << "sucessfully updated to "
                 << "Node [" << ptr->key << "," << ptr->data << "]" << endl;
        }
    }
    // 8. return length of list
    int length()
    {
        Node *ptr = head;
        int len = 0;
        while (ptr != NULL)
        {
            ptr = ptr->next;
            len++;
        }
        return len;
    }
    // 9.  reversing the list
    void reverseList()
    {
        Node *left = head;
        Node *right = head;
        int i = 0;
        int j = length() - 1;
        while (i < j)
        {
            int k = 0;
            while (k < j)
            {
                right = right->next;
                k++;
            }
            int temp = left->data;
            left->data = right->data;
            right->data = temp;
            i++;
            j--;
            left = left->next;
            right = head;
        }
        cout << "List successfully reversed" << endl;
    }
};

int main()
{
    int option = 0;
    singlylinkedlist list;
    while (true)
    {
        cout << endl
             << "---------" << endl;
        cout << "Options : " << endl;
        cout << "---------" << endl;
        cout << "1) Append a node to the list" << endl;
        cout << "2) Prepend a node to the list" << endl;
        cout << "3) insert a node after another node" << endl;
        cout << "4) delete a node from list" << endl;
        cout << "5) Update a node from list" << endl;
        cout << "6) Reverse the list" << endl;
        cout << "7) Print length of the list" << endl;
        cout << "8) Print the list" << endl;
        cout << "9) exit" << endl;
        cout << "Please enter an option [1/2/3/4/5/6/7/8/9] : ";
        cin >> option;
        if (option == 1)
        {
            Node *n = new Node;
            cout << "Please enter a Number to store in list : ";
            cin >> n->data;
            list.appendNode(n);
        }
        else if (option == 2)
        {
            Node *n = new Node;
            cout << "Please enter a Number to store in list : ";
            cin >> n->data;
            list.prependNode(n);
        }
        else if (option == 3)
        {
            Node *n = new Node;
            int k;
            cout << "Please enter a Number to store in list : ";
            cin >> n->data;
            cout << "Please enter a key that you want to insert this node after : ";
            cin >> k;
            list.insertNodeAfter(k, n);
        }
        else if (option == 4)
        {
            int k;
            cout << "Please enter key of node you want to delete: ";
            cin >> k;
            list.deleteNodeByKey(k);
        }
        else if (option == 5)
        {
            int k, d;
            cout << "Please enter key of node you want to update: ";
            cin >> k;
            cout << "Please a number to update the node with : ";
            cin >> d;
            list.updateNodeByKey(k, d);
        }
        else if (option == 6)
        {
            list.reverseList();
        }
        else if (option == 7)
        {
            cout << "length of the list is : " << list.length() << endl;
        }
        else if (option == 8)
        {
            list.printList();
        }
        else if (option == 9)
        {
            cout << "Exiting..." << endl
                 << endl;
            break;
        }
    }
    return 0;
}