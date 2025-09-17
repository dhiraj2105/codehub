package swe130challenge.day2;

import java.util.Arrays;

public class rotate {
    public static void main(String[] args) {
        int[] arr = { 1, 2, 3, 4, 5 };
        int k = 2; // Number of positions to rotate

        System.out.println("Original Array: " + Arrays.toString(arr));
        rotateLeft(arr, k);
        System.out.println("Array after " + k + " left rotations: " + Arrays.toString(arr));
    }

    public static void rotateLeft(int[] arr, int k) {
        int n = arr.length;
        k = k % n; // Handle if k > n

        reverse(arr, 0, k - 1);
        reverse(arr, k, n - 1);
        reverse(arr, 0, n - 1);
    }

    public static void reverse(int[] arr, int start, int end) {
        while (start < end) {
            int temp = arr[start];
            arr[start++] = arr[end];
            arr[end--] = temp;
        }
    }

}
