#include <iostream>
using namespace std;
int recursiveBinarySearch(int array[], int start_index, int end_index, int element)
{
    if (end_index >= start_index)
    {
        int middle = start_index + (end_index - start_index) / 2;
        if (array[middle] == element)
            return middle;
        if (array[middle] > element)
            return recursiveBinarySearch(array, start_index, middle - 1, element);
        return recursiveBinarySearch(array, middle + 1, end_index, element);
    }
    return -1;
}
int main(void)
{
    int n;
    int array[] = {1, 4, 7, 9, 16, 56, 70};
    cout << "Enter a number to search the array: ";
    cin >> n;
    int element = 9;
    int found_index = recursiveBinarySearch(array, 0, n - 1, element);
    if (found_index == -1)
    {
        printf("Element not found in the array\n");
    }
    else
    {
        printf("Element found at index : %d\n", found_index);
    }
    return 0;
}