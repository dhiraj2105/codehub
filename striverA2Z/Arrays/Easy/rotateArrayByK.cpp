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
 * rotate the array by k to direction of choice, left or right
 * @param nums[] array
 * @param size size of the array
 * @param choice direction
 * @param k k elements to rotate
 */
void bruteForce(int nums[], int size, string choice, int k)
{
    int temp[k];

    if (choice == "left")
    {
        for (int i = 0; i < k; i++)
        {
            temp[i] = nums[i];
        }

        for (int i = 0; i < size - k; i++)
        {
            nums[i] = nums[i + k];
        }

        for (int i = 0; i < k; i++)
        {
            nums[size - k + i] = temp[i];
        }

        print("rotated to left", nums, size);
    }
    else
    {
        for (int i = 0; i < k; i++)
        {
            temp[i] = nums[size - k + i];
        }

        for (int i = size - 1; i >= k; i--)
        {
            nums[i] = nums[i - k];
        }

        for (int i = 0; i < k; i++)
        {
            nums[i] = temp[i];
        }

        print("rotated to right", nums, size);
    }
}

/**
 * reverse the array
 * @param nums[] array
 * @param start left index
 * @param end right index
 */
void reverse(int nums[], int start, int end)
{
    while (start < end)
    {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;

        start++;
        end--;
    }
}

/**
 * optimal solution
 * @param nums[] array
 * @param size size of the array
 * @param choice direction
 * @param k k elements to rotate
 */
void optimal(int nums[], int size, string choice, int k)
{
    if (choice == "left")
    {
        reverse(nums, 0, k - 1);
        reverse(nums, k, size - 1);
        reverse(nums, 0, size - 1);

        print("Reversed array", nums, size);
    }
    else
    {
        reverse(nums, 0, size - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, size - 1);

        print("Reversed array", nums, size);
    }
}

int main()
{
    // Given an integer array nums, rotate the array to the left or right by k elements.

    int nums[] = {1, 2, 3, 4, 5};
    int size = sizeof(nums) / sizeof(nums[0]);
    string choice = "right";
    int k = 3;

    print("Original array", nums, size);

    optimal(nums, size, choice, k);

    return 0;
}