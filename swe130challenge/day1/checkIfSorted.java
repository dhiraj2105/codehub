package swe130challenge.day1;

public class checkIfSorted {

    public static void main(String[] args) {
        int nums[] = { 1, 2, 3, 4, 5 };

        for (int i = 0; i < nums.length - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                System.out.println("Array is not sorted");
                return;
            }
        }
        System.out.println("Array is sorted");
    }
}