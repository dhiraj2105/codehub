#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>> &matrix)
{
    // we will use swapping
    int n = matrix.size();

    for (int layer = 0; layer < (n + 1) / 2; layer++)
    {
        for (int index = 0; index < n / 2; index++)
        {
            // temp =  lastStart
            int lastStart = matrix[n - 1 - index][layer];

            // leftStart =  leftEnd
            matrix[n - 1 - index][layer] = matrix[n - 1 - layer][n - index - 1];

            // leftEnd = firstEnd
            matrix[n - 1 - layer][n - index - 1] = matrix[index][n - 1 - layer];

            // firstEnd = firstStart
            matrix[index][n - 1 - layer] = matrix[layer][index];

            // firstStart = temp
            matrix[layer][index] = lastStart;
        }
    }
}

int main()
{
    /*
    You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

    You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
    */

    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    rotate(matrix);

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << " | ";
    }

    return 0;
}