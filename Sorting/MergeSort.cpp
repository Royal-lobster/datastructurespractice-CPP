#include <iostream>
using namespace std;

//function declaration
void merge(int arr[], int l, int m, int r, int size);
void mergeSort(int arr[], int l, int r, int size);
void printArr(int arr[], int size);

//main function
int main()
{
    int myArr[] = {1, 6, 8, 7, 5, 4, 3, 2};
    int size = sizeof(myArr) / sizeof(int);
    cout << "Unsorted Array: \n";
    printArr(myArr, size);
    mergeSort(myArr, 0, size - 1, size);
    cout << "Sorted Array: \n";
    printArr(myArr, size);
    return 0;
}

// Functions
void mergeSort(int arr[], int l, int r, int size)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergeSort(arr, l, m, size);
        mergeSort(arr, m + 1, r, size);
        merge(arr, l, m, r, size);
    }
}
void merge(int arr[], int l, int m, int r, int size)
{
    //initalizing our temp array
    int temp[size];
    //initalizing 2 pointer indices
    int i = l;
    int j = m + 1;
    int k = l;

    while (i <= m && j <= r)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= m)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j <= r)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }
    for (int p = l; p <= r; p++)
    {
        arr[p] = temp[p];
    }
};

void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
