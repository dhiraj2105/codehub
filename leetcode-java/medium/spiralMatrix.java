import java.util.ArrayList;
import java.util.List;

public class spiralMatrix {

    public static List<Integer> spiralOrder(int[][] matrix) {
        // Create a list to store the result
        List<Integer> res = new ArrayList<>();

        // Initialize the boundaries of the matrix (top, bottom, left, right)
        int rowBegin = 0, rowEnd = matrix.length - 1;
        int colBegin = 0, colEnd = matrix[0].length - 1;

        // Loop until all elements are visited (i.e., rowBegin <= rowEnd and colBegin <=
        // colEnd)
        while (rowBegin <= rowEnd && colBegin <= colEnd) {
            // Step 1: Traverse from left to right along the top row (rowBegin)
            for (int i = colBegin; i <= colEnd; i++) {
                res.add(matrix[rowBegin][i]);
            }
            // After traversing the top row, move the top boundary down
            rowBegin++;

            // Step 2: Traverse from top to bottom along the right column (colEnd)
            for (int i = rowBegin; i <= rowEnd; i++) {
                res.add(matrix[i][colEnd]);
            }
            // After traversing the right column, move the right boundary left
            colEnd--;

            // Step 3: Traverse from right to left along the bottom row (rowEnd)
            // This step is only performed if there are remaining rows to traverse
            if (rowBegin <= rowEnd) {
                for (int i = colEnd; i >= colBegin; i--) {
                    res.add(matrix[rowEnd][i]);
                }
            }
            // After traversing the bottom row, move the bottom boundary up
            rowEnd--;

            // Step 4: Traverse from bottom to top along the left column (colBegin)
            // This step is only performed if there are remaining columns to traverse
            if (colBegin <= colEnd) {
                for (int i = rowEnd; i >= rowBegin; i--) {
                    res.add(matrix[i][colBegin]);
                }
            }
            // After traversing the left column, move the left boundary right
            colBegin++;
        }

        // Return the result containing the elements in spiral order
        return res;
    }

    public static void main(String[] args) {
        // Example input matrix
        int[][] matrix = {
                { 1, 2, 3 },
                { 4, 5, 6 },
                { 7, 8, 9 } };

        // Call the spiralOrder function and get the result
        List<Integer> result = spiralOrder(matrix);

        // Output the result
        for (int num : result) {
            System.out.print(num + " ");
        }
    }
}
