#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }

    // print array
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[10] = {11, 4, 2, 55, 3, 7, 4, 6, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);
    return 0;
}