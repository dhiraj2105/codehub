public class multiDimensional {

    public static void main(String[] args) {
        // ===========================
        // 2D Array Example
        // ===========================

        // Declaration and Initialization of a 2D array
        int[][] arr2D = { { 1, 2, 3 }, { 4, 5, 6 } };

        // Accessing elements in the 2D array
        System.out.println("2D Array Elements:");
        System.out.println("Element at (0, 1): " + arr2D[0][1]); // Accessing element in 1st row, 2nd column
        System.out.println("Element at (1, 2): " + arr2D[1][2]); // Accessing element in 2nd row, 3rd column

        // Traversing the 2D array using nested loops
        System.out.println("Traversing 2D Array:");
        for (int i = 0; i < arr2D.length; i++) { // Loop through rows
            for (int j = 0; j < arr2D[i].length; j++) { // Loop through columns
                System.out.print(arr2D[i][j] + " "); // Print each element
            }
            System.out.println(); // New line after each row
        }

        // ===========================
        // 3D Array Example
        // ===========================

        // Declaration and Initialization of a 3D array
        int[][][] arr3D = {
                { { 1, 2, 3 }, { 4, 5, 6 } },
                { { 7, 8, 9 }, { 10, 11, 12 } }
        };

        // Accessing elements in the 3D array
        System.out.println("3D Array Elements:");
        System.out.println("Element at (0, 1, 2): " + arr3D[0][1][2]); // Accessing element in 1st block, 2nd row, 3rd
                                                                       // column
        System.out.println("Element at (1, 0, 1): " + arr3D[1][0][1]); // Accessing element in 2nd block, 1st row, 2nd
                                                                       // column

        // Traversing the 3D array using nested loops
        System.out.println("Traversing 3D Array:");
        for (int i = 0; i < arr3D.length; i++) { // Loop through blocks
            for (int j = 0; j < arr3D[i].length; j++) { // Loop through rows
                for (int k = 0; k < arr3D[i][j].length; k++) { // Loop through columns
                    System.out.print(arr3D[i][j][k] + " "); // Print each element
                }
                System.out.println(); // New line after each row
            }
            System.out.println("-----"); // Separator between blocks
        }
    }
}