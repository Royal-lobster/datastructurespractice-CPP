#include <iostream>
using namespace std;

int i = 0;
int linearSearch(int arr[], int n, int l, int r)
{
    if (r < l)
    {
        return -1;
    }
    if (arr[l] == n)
    {
        return l;
    }
    if (arr[r] == n)
    {
        return r;
    }
    return linearSearch(arr, n, l + 1, r - 1);
}
int main()
{
    int arr[] = {1, 4, 5, 2, 3, 7, 8, 9, 6};
    int size = sizeof(arr) / sizeof(int);
    int n;
    cout << "Enter a number to search the array: ";
    cin >> n;
    int index = linearSearch(arr, n, 0, size - 1);
    if (index != -1)
    {
        cout << "The element " << n << " is located at index: " << index << endl;
    }
    else
        cout << "The element you searched is not in the array\n";
    return 0;
}
