#include <iostream>
using namespace std;

//function declaration
void mergeSort(int arr[], int size);
void printArr(int arr[], int size);

//main function
int main()
{
    int arr[] = {1, 6, 8, 7, 5, 4, 3, 2};
    int size = sizeof(arr) / sizeof(int);
    cout << "Unsorted Array: \n";
    printArr(arr, size);
    mergeSort(arr, size);
    cout << "Sorted Array: \n";
    printArr(arr, size);
    return 0;
}

// Functions
void mergeSort(int arr[], int size)
{
    int temp;
    bool swapped = false;
    for (int i = 0; i < size - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped)
        {
            break;
        }
    }
}
void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
