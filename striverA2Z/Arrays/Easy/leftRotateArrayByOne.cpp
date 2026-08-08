#include <bits/stdc++.h>
using namespace std;

/**
 * print the array
 * @param msg message to print
 * @param nums[] array
 * @param size size of the array
 */
void print(string msg, int nums[], int size)
{
    cout << msg << " : ";
    for (int i = 0; i < size; i++)
    {
        cout << nums[i];
    }
    cout << endl;
}

/**
 * Left Rotate an array by one
 * @param nums[] array
 * @param size size of the array
 */
void rotate(int nums[], int size)
{
    // pick the first element and put it in a tmep variable
    // swap the positions of rest of the lements to left by one
    // put the picked element in last index

    int temp = nums[0];

    for (int i = 0; i < size - 1; i++)
    {
        nums[i] = nums[i + 1];
    }
    nums[size - 1] = temp;

    print("Rotated Array : ", nums, size);
}

int main()
{
    // Given an integer array nums, rotate the array to the left by one.

    int nums[] = {1, 2, 3, 4, 5};
    int size = sizeof(nums) / sizeof(nums[0]);

    print("Original array", nums, size);

    rotate(nums, size);

    return 0;
}