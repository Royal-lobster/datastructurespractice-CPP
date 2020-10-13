#include <iostream>
using namespace std;

//function declaration
void selectionSort(int arr[], int size);
void printArr(int arr[], int size);

//main function
int main()
{
    int arr[] = {5, 4, 1, 3, 2};
    int size = sizeof(arr) / sizeof(int);
    cout << "Unsorted Array: \n";
    printArr(arr, size);
    selectionSort(arr, size);
    cout << "Sorted Array: \n";
    printArr(arr, size);
    return 0;
}

// Functions
void selectionSort(int arr[], int size)
{
    int minIndex;
    int temp;

    for (int i = 0; i < size - 1; i++)
    {
        minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[minIndex] > arr[j])
            {
                temp = arr[minIndex];
                arr[minIndex] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
