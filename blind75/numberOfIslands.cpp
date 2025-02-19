#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    // Helper function to perform BFS
    void bfs(int row, int col, vector<vector<int>> &visited, vector<vector<char>> &grid)
    {
        visited[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});

        // Define the directions (up, down, left, right)
        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            // Traverse 4 directions
            for (int i = 0; i < 4; i++)
            {
                int nrow = r + directions[i][0];
                int ncol = c + directions[i][1];

                if (nrow >= 0 && nrow < grid.size() && ncol >= 0 && ncol < grid[0].size() &&
                    grid[nrow][ncol] == '1' && !visited[nrow][ncol])
                {
                    visited[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<int>> visited(n, vector<int>(m, 0));

        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < m; col++)
            {
                if (!visited[row][col] && grid[row][col] == '1')
                {
                    count++;
                    bfs(row, col, visited, grid); // perform BFS to mark all connected land as visited
                }
            }
        }
        return count;
    }
};

// Test cases
int main()
{

    /*
    Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

    An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
    */

    Solution solution;

    // Test case 1: A grid with 3 islands
    vector<vector<char>> grid1 = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}};
    cout << "Test case 1: " << solution.numIslands(grid1) << endl; // Expected output: 3

    // Test case 2: A grid with no islands (only water)
    vector<vector<char>> grid2 = {
        {'0', '0', '0', '0'},
        {'0', '0', '0', '0'},
        {'0', '0', '0', '0'},
        {'0', '0', '0', '0'}};
    cout << "Test case 2: " << solution.numIslands(grid2) << endl; // Expected output: 0

    // Test case 3: A grid with one large island
    vector<vector<char>> grid3 = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '1', '1', '0'},
        {'1', '1', '1', '1', '0'},
        {'0', '0', '0', '0', '0'}};
    cout << "Test case 3: " << solution.numIslands(grid3) << endl; // Expected output: 1

    // Test case 4: A grid with 1 island
    vector<vector<char>> grid4 = {
        {'1', '0', '1'},
        {'1', '1', '1'},
        {'0', '1', '0'}};
    cout << "Test case 4: " << solution.numIslands(grid4) << endl; // Expected output: 1

    // Test case 5: A grid with multiple isolated islands
    vector<vector<char>> grid5 = {
        {'1', '0', '1', '0', '1'},
        {'0', '1', '0', '1', '0'},
        {'1', '0', '1', '0', '1'}};
    cout << "Test case 5: " << solution.numIslands(grid5) << endl; // Expected output: 5

    return 0;
}
