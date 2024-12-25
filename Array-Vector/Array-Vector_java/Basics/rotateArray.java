
public class rotateArray {
    public static void main(String[] args) {
        // Initialize the array and the rotation factor
        int[] arr = { 1, 2, 3, 4, 5 };
        int k = 2;

        // Create a temporary array to hold the rotated values
        int[] temp = new int[arr.length];

        // Rotate the array
        for (int i = 0; i < arr.length; i++) {
            temp[(i + k) % arr.length] = arr[i];
        }

        // Copy the temporary array back into the original array
        arr = temp;

        // Print the rotated array
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
    }
}