import java.util.Arrays;

public class removeDuplicates {
    public static void main(String[] args) {
        // Remove duplicates
        int[] nums = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
        Arrays.sort(nums); // Sort the array

        int i = 1; // Index for the unique elements
        int j = 1; // Index for iterating through the array

        while (j < nums.length) {
            if (nums[j] != nums[j - 1]) {
                nums[i] = nums[j];
                i++;
            }
            j++;
        }

        System.out.println(i); // Print the count of unique elements

        // Print the unique elements
        for (int k = 0; k < i; k++) {
            System.out.print(nums[k] + " ");
        }
    }
}