#include <bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int> &nums)
{
    // Get the size of the input array.
    int n = nums.size();

    // Create a new array to store the products, initialized with 1's.
    // This array will have the same size as the input array.
    std::vector<int> product(n, 1);

    // Calculate the prefix products.
    // The prefix product at index i is the product of all numbers from index 0 to i-1.
    for (int i = 1; i < n; i++)
    {
        // For each index i, calculate the prefix product by multiplying the previous prefix product with the number at index i-1.
        product[i] = product[i - 1] * nums[i - 1];
    }

    // Initialize a variable to store the suffix product.
    // The suffix product starts from the last number in the array and moves towards the first number.
    int right = 1;

    // Calculate the suffix products and multiply with the prefix products.
    // The suffix product at index i is the product of all numbers from index i+1 to the end of the array.
    for (int i = n - 1; i >= 0; i--)
    {
        // For each index i, calculate the product by multiplying the prefix product with the suffix product.
        product[i] = product[i] * right;

        // Update the suffix product by multiplying it with the number at index i.
        right = right * nums[i];
    }

    // Return the array of products.
    return product;
}

int main()
{

    /*
    Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

    The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

    You must write an algorithm that runs in O(n) time and without using the division operation.
    */
    vector<int> nums = {1, 2, 3, 4};

    vector<int> result = productExceptSelf(nums);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}