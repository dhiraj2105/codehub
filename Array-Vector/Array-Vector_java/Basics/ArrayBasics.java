public class ArrayBasics {
    public static void main(String[] args) {
        // **Basics of Arrays in Java**

        // 1. Declaration and Initialization of Arrays
        int[] arr = { 1, 2, 3, 4, 5 }; // Array of 5 integers initialized with values
        int[] arr2 = new int[5]; // Declaration of an array of 5 integers (uninitialized)

        // 2. Inserting Elements into an Array
        arr2[0] = 10; // Assigning value 10 to the first element
        arr2[1] = 20; // Assigning value 20 to the second element
        arr2[2] = 30; // Assigning value 30 to the third element
        arr2[3] = 40; // Assigning value 40 to the fourth element
        arr2[4] = 50; // Assigning value 50 to the fifth element

        // 3. Accessing Elements of an Array
        System.out.println("First element of arr: " + arr[0]); // Output: 1
        System.out.println("First element of arr2: " + arr2[0]); // Output: 10
        System.out.println("Second element of arr2: " + arr2[1]); // Output: 20

        // 4. Traversing an Array
        System.out.print("Elements of arr: ");
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " "); // Print each element of arr
        }
        System.out.println(); // New line after printing all elements

        // 5. Deleting a Specific Element from an Array
        // Note: In Java, arrays have a fixed size and do not support deletion of
        // elements.
        // To "delete" an element, you can set it to a default value (e.g., 0) or use a
        // new array.

        // Example of setting an element to 0 (logical deletion)
        arr[2] = 0; // Setting the third element to 0
        System.out.print("After logical deletion, elements of arr: ");
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " "); // Print each element of arr after deletion
        }
        System.out.println(); // New line after printing all elements
    }
}