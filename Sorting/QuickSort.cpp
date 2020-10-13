#include <iostream>
using namespace std;

//function declaration
void printArr(int arr[], int);
void swapArrElements(int arr[], int, int);
int partition(int arr[], int, int);
void quickSort(int arr[], int, int);

//main function
int main()
{
    int arr[] = {1, 6, 8, 7, 5, 4, 3, 2};
    int arrSize = sizeof(arr) / sizeof(int);
    cout << "Before Sorting: \n";
    printArr(arr, arrSize);
    quickSort(arr, 0, (arrSize - 1));
    cout << "After Sorting: \n";
    printArr(arr, arrSize);
}

//functions
void printArr(int arr[], int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swapArrElements(int arr[], int a, int b)
{
    int temp;
    temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int partition(int arr[], int start, int end)
{
    int pivot = arr[end];
    int pIndex = start;
    for (int i = start; i < end; i++)
    {
        if (arr[i] < pivot)
        {
            swapArrElements(arr, i, pIndex);
            pIndex++;
        }
    }
    swapArrElements(arr, end, pIndex);
    return pIndex;
}

void quickSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int p = partition(arr, start, end);
        quickSort(arr, start, (p - 1));
        quickSort(arr, (p + 1), end);
    }
}
