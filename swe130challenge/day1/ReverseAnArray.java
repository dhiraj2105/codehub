package swe130challenge.day1;

class ReverseArray {
    void reverseArray(int[] arr) {
        int start = 0;
        int end = arr.length - 1;
        int temp;

        while (start < end) {
            // swap the elements
            temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;

            // move the pointers
            start++;
            end--;
        }
    }

    void printArray(int[] arr) {
        for (int num : arr) {
            System.out.print(num + " ");
        }
        System.out.println();
    }
}

public class ReverseAnArray {

    public static void main(String[] args) {

        // creating an array
        int[] nums = { 1, 2, 3, 4, 5 };

        ReverseArray ra = new ReverseArray();

        System.out.println("Original Array:");
        ra.printArray(nums);

        ra.reverseArray(nums);
        System.out.println("Reversed Array:");
        ra.printArray(nums);
    }
}