package swe130challenge.day1;

public class minMaxInArray {
    static int findMin(int nums[]) {
        int min = nums[0];

        for (int i = 1; i < nums.length; i++) {
            if (nums[i] < min) {
                min = nums[i];
            }
        }
        return min;
    }

    static int findMax(int nums[]) {
        int max = nums[0];

        for (int i = 1; i < nums.length; i++) {
            if (nums[i] > max) {
                max = nums[i];
            }
        }
        return max;
    }

    public static void main(String[] args) {
        int[] numbers = { 3, 5, 1, 8, 2 };

        int min = findMin(numbers);
        int max = findMax(numbers);

        System.out.println("Minimum: " + min);
        System.out.println("Maximum: " + max);
    }
}
