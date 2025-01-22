import java.util.Arrays;

public class setMatrixZeroes {

    public static void setZeroes(int[][] matrix) {
        // Initialize two flags to check if the first row and first column need to be
        // set to zero
        boolean firstRow = false, firstCol = false;

        // Get the number of rows and columns in the matrix
        int m = matrix.length, n = matrix[0].length;

        // Step 1: Check for zeroes and mark the first row and first column
        for (int i = 0; i < m; i++) { // Loop through all the rows
            for (int j = 0; j < n; j++) { // Loop through all the columns
                // If we find a zero in the matrix
                if (matrix[i][j] == 0) {
                    // Mark the first row and first column to indicate that
                    // this row or column will be set to zero later
                    if (i == 0) // If it's in the first row
                        firstRow = true;
                    if (j == 0) // If it's in the first column
                        firstCol = true;

                    // Set the first cell in the current row (matrix[i][0]) and
                    // the first cell in the current column (matrix[0][j]) to 0
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        // Step 2: Set zeroes for the inner matrix, based on the marks in the first row
        // and column
        for (int i = 1; i < m; i++) { // Loop through rows, starting from the second row
            for (int j = 1; j < n; j++) { // Loop through columns, starting from the second column
                // If the first cell of the current row or column is zero, set the current cell
                // to zero
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Step 3: Set zeroes in the first row, if needed
        if (firstRow) { // If we found a zero in the first row during Step 1
            for (int j = 0; j < n; j++) { // Loop through the first row
                matrix[0][j] = 0; // Set every element in the first row to zero
            }
        }

        // Step 4: Set zeroes in the first column, if needed
        if (firstCol) { // If we found a zero in the first column during Step 1
            for (int i = 0; i < m; i++) { // Loop through the first column
                matrix[i][0] = 0; // Set every element in the first column to zero
            }
        }
    }

    public static void main(String[] args) {
        // Example input matrix
        int[][] matrix = {
                { 1, 1, 1 },
                { 1, 0, 1 },
                { 1, 1, 1 }
        };

        // Call the setZeroes function to modify the matrix
        setZeroes(matrix);

        // Output the modified matrix
        for (int[] row : matrix) {
            System.out.println(Arrays.toString(row));
        }
    }
}
