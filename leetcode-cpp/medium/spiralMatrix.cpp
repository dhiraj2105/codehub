#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    // Create a vector to store the result
    vector<int> res;

    // Initialize the boundaries of the matrix (top, bottom, left, right)
    int rowBegin = 0, rowEnd = matrix.size() - 1;
    int colBegin = 0, colEnd = matrix[0].size() - 1;

    // Loop until all elements are visited (i.e., rowBegin <= rowEnd and colBegin <= colEnd)
    while (rowBegin <= rowEnd && colBegin <= colEnd)
    {
        // Step 1: Traverse from left to right along the top row (rowBegin)
        for (int i = colBegin; i <= colEnd; i++)
        {
            // Add the element to the result
            res.push_back(matrix[rowBegin][i]);
        }
        // After traversing the top row, move the top boundary down
        rowBegin++;

        // Step 2: Traverse from top to bottom along the right column (colEnd)
        for (int i = rowBegin; i <= rowEnd; i++)
        {
            // Add the element to the result
            res.push_back(matrix[i][colEnd]);
        }
        // After traversing the right column, move the right boundary left
        colEnd--;

        // Step 3: Traverse from right to left along the bottom row (rowEnd)
        // This step is only performed if there are remaining rows to traverse
        if (rowBegin <= rowEnd)
        {
            for (int i = colEnd; i >= colBegin; i--)
            {
                // Add the element to the result
                res.push_back(matrix[rowEnd][i]);
            }
        }
        // After traversing the bottom row, move the bottom boundary up
        rowEnd--;

        // Step 4: Traverse from bottom to top along the left column (colBegin)
        // This step is only performed if there are remaining columns to traverse
        if (colBegin <= colEnd)
        {
            for (int i = rowEnd; i >= rowBegin; i--)
            {
                // Add the element to the result
                res.push_back(matrix[i][colBegin]);
            }
        }
        // After traversing the left column, move the left boundary right
        colBegin++;
    }

    // Return the result containing the elements in spiral order
    return res;
}

int main()
{
    /*
    Given an m x n matrix, return all elements of amtrix in spiral order [clockwise]
    */
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    vector<int> result = spiralOrder(matrix);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}