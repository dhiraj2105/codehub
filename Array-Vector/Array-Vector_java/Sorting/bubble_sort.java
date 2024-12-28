import java.util.Arrays;

public class bubble_sort {

    public static void main(String[] args) {
        // Initialize the array
        int[] nums = { 9, 4, 7, 5, 2, 1, 3, 6 };

        // Bubble sort algorithm
        for (int i = 0; i < nums.length - 1; i++) {
            for (int j = 0; j < nums.length - 1 - i; j++) {
                // Compare adjacent elements and swap if they are in the wrong order
                if (nums[j] > nums[j + 1]) {
                    // Swap nums[j] and nums[j + 1]
                    int temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                }
            }
        }

        // Print the sorted array
        System.out.println(Arrays.toString(nums));
    }
}