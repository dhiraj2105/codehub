public class reverseArray {
    public static void main(String[] args) {
        // Time Complexity: O(n^2)
        int[] arr = { 1, 2, 1, 3, 4, 5 };

        // Nested loops to swap elements
        for (int i = 0; i < arr.length; i++) {
            for (int j = i + 1; j < arr.length; j++) {
                // Swap elements at index i and j
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        // Output: Print the modified array
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
    }
}