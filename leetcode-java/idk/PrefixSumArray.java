public class PrefixSumArray {
    public static void main(String[] args) {
        // Given an array arr[] of size N, find the prefix sum of the array.
        int[] arr = { 10, 20, 10, 5, 15 };

        // Initialize prefixSumArray
        int[] prefixSumArray = new int[arr.length];

        // Setting first index of prefix array to same as arr
        prefixSumArray[0] = arr[0];

        // Finding prefix sum
        for (int i = 1; i < arr.length; i++) {
            prefixSumArray[i] = prefixSumArray[i - 1] + arr[i];
        }

        // Print array
        for (int i = 0; i < prefixSumArray.length; i++) {
            System.out.print(prefixSumArray[i] + " ");
        }
    }
}