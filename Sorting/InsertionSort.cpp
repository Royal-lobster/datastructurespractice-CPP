#include <iostream>
using namespace std;

//function declaration
void insertionSort(int arr[], int size);
void printArr(int arr[], int size);

//main function
int main()
{
    int arr[] = {1, 6, 8, 7, 5, 4, 3, 2};
    int size = sizeof(arr) / sizeof(int);
    cout << "Unsorted Array: \n";
    printArr(arr, size);
    insertionSort(arr, size);
    cout << "Sorted Array: \n";
    printArr(arr, size);
    return 0;
}

// Functions
void insertionSort(int arr[], int size)
{
    int valueToInsert;
    int holePosition;
    for (int i = 1; i < size; i++)
    {
        valueToInsert = arr[i];
        holePosition = i;
        while (holePosition >= 0 && arr[holePosition - 1] > valueToInsert)
        {
            arr[holePosition] = arr[holePosition - 1];
            holePosition = holePosition - 1;
        }
        arr[holePosition] = valueToInsert;
    }
}
void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
