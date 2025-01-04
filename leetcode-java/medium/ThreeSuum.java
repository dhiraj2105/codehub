import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;

public class ThreeSuum {
    public static List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);

        HashSet<List<Integer>> set = new HashSet<>();

        for (int i = 0; i < nums.length; i++) {
            // Skip duplicates for the first element
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1, right = nums.length - 1;

            while (left < right) {

                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    set.add(Arrays.asList(nums[i], nums[left], nums[right]));
                    left++;
                    right--;
                } else if (sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        return new ArrayList<>(set);
    }

    public static void main(String[] args) {
        /*
         * Given an integer array nums, return all the triplets [nums[i], nums[j],
         * nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] +
         * nums[k] == 0.
         * 
         * Notice that the solution set must not contain duplicate triplets.
         */
        int[] nums = { -1, 0, 1, 2, -1, -4 };
        List<List<Integer>> result = threeSum(nums);

        // Print the result
        for (List<Integer> triplet : result) {
            System.out.println(triplet);
        }
    }
}