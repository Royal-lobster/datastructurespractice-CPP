// C++ implementation of Radix Sort
#include <iostream>
using namespace std;

// print array function
void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
// A utility function to get maximum value in arr[]
int getMax(int arr[], int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void CountingSort(int arr[], int size, int div)
{
    int output[size];
    int count[10] = {0};

    for (int i = 0; i < size; i++)
        count[(arr[i] / div) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = size - 1; i >= 0; i--)
    {
        output[count[(arr[i] / div) % 10] - 1] = arr[i];
        count[(arr[i] / div) % 10]--;
    }

    for (int i = 0; i < size; i++)
        arr[i] = output[i];
}

void RadixSort(int arr[], int size)
{
    int m = getMax(arr, size);
    for (int div = 1; m / div > 0; div *= 10)
        CountingSort(arr, size, div);
}

int main()
{
    int myArr[] = {1, 6, 8, 7, 5, 4, 3, 2};
    int size = sizeof(myArr) / sizeof(int);
    cout << "Unsorted Array: \n";
    printArr(myArr, size);
    RadixSort(myArr, size);
    cout << "Sorted Array: \n";
    printArr(myArr, size);
    return 0;
}