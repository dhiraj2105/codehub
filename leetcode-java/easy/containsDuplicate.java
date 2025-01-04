import java.util.Arrays;

public class containsDuplicate {
    public static boolean contains_duplicate(int[] nums) {

        boolean isDuplicate = false;

        Arrays.sort(nums);
        int left = 0, right = 1;

        while (right < nums.length) {
            if (nums[right] == nums[left]) {
                isDuplicate = true;
            } else {
                left++;
            }
            right++;
        }

        return isDuplicate;
    }

    public static void main(String[] args) {
        /*
         * Given an integer array nums, return true if any value appears at least twice
         * in the array, and return false if every element is distinct.
         */
        int[] nums = { 1, 2, 3, 2 };

        System.out.println(contains_duplicate(nums));
    }
}
