#include <iostream>
using namespace std;

//function declarations
void towerOfHanoi(int n, char from_tower, char aux_tower, char to_tower);

//main function
int main()
{
    int n;
    cout << "Enter the number of rings: ";
    cin >> n;
    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}

//functions
void towerOfHanoi(int n, char from_tower, char to_tower, char aux_tower)
{
    if (n == 1)
    {
        cout << "move disk " << n << " from " << from_tower << " to " << to_tower << endl;
        return;
    }
    else
    {
        towerOfHanoi(n - 1, from_tower, aux_tower, to_tower);
        cout << "move disk " << n << " from " << from_tower << " to " << to_tower << endl;
        towerOfHanoi(n - 1, aux_tower, to_tower, from_tower);
    }
}